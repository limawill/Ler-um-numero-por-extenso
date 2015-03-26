#include "leitor.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <locale>
#include <list>
#include <sstream>





std::string Pontuacao (std::string Values)
{
    char String[14];
    double money;
    unsigned int TamanhoTotal=0,Centavos=0;
    std::string Apoio;

    TamanhoTotal = Values.size();

    if(TamanhoTotal <= 2)
    {

        Apoio   = "R$ 0," + Values;
        return Apoio;
    }
    else
    {
        Centavos = TamanhoTotal -3;

        for(int i=0; i<=TamanhoTotal;++i)
        {
            if(i != Centavos)
                Apoio = Apoio+Values[i];
            else
                Apoio = Apoio+Values[i]+".";
        }

        money = atof(Apoio.c_str());
        std::string str = formataReal(money);
        return str;
    }
}


void Extenso (std::string Value)
{

    std::vector<std::string> Quebras;
    int posicao=0;
    unsigned int Centavos=0,Reais=0,Mil=0,Milhoes=0,Bilhoes=0,Trilhoes=0;
    std::string aux2;


    //Removendo o Cifrão
    replace_str(Value,"R$ ","");

    //Separando os Centavos
    separar(Value,',',Quebras);

    //Verificando se há ponto
    aux2 = Quebras[0];
    posicao = aux2.find(".");


    if(posicao == -1)
    {
        Reais    = Conversao_inteiro(Quebras[0]);
        Centavos = Conversao_inteiro(Quebras[1]);

        if(Reais == 0)
        {
            aux2 = Escrita(Centavos) + " centavos";
        }
        else
        {

            if(Reais == 1)
                aux2 = Escrita(Reais) + " real e " + Escrita(Centavos) + " centavos";

            else
                aux2 = Escrita(Reais) + " reais e " + Escrita(Centavos) + " centavos";
        }

    }
    else
    {
        for(int i = 0; i < Quebras.size(); ++i)
        {
            if((i == 0))
            {
                aux2 = Quebras[i];
                separar(aux2,'.',Quebras);
                Quebras.erase(Quebras.begin());
                aux2 = Quebras[i];
                Quebras.push_back(aux2);
                Quebras.erase(Quebras.begin());
            }
            //std::cout << "Campo " << i << " = " << Quebras[i] << '\n';
        }

        if(Quebras.size() == 3)
        {
            Mil  = Conversao_inteiro(Quebras[0]);
            Reais    = Conversao_inteiro(Quebras[1]);
            Centavos = Conversao_inteiro(Quebras[2]);

            if(Reais == 1)
            {
                aux2 = Escrita(Mil) + " Mil, " + Escrita(Reais) + " real e " + Escrita(Centavos) + " centavos";

            }
            else
            {
                aux2 = Escrita(Mil) + " Mil, " +  Escrita(Reais) + " reais e " + Escrita(Centavos) + " centavos";

            }
        }


        if(Quebras.size() == 4)
        {
            Milhoes  = Conversao_inteiro(Quebras[0]);
            Mil      = Conversao_inteiro(Quebras[1]);
            Reais    = Conversao_inteiro(Quebras[2]);
            Centavos = Conversao_inteiro(Quebras[3]);


            if((Milhoes == 1) && (Reais == 1))
                aux2 = Escrita(Milhoes)+" milhao, "+  Escrita(Mil) + " Mil, " + Escrita(Reais) + " real e " + Escrita(Centavos) + " centavos";
            else if(Milhoes == 1)
                aux2 = Escrita(Milhoes)+" milhao, " +  Escrita(Mil) + " Mil, " + Escrita(Reais) + " reais e " + Escrita(Centavos) + " centavos";
            else
                aux2 = Escrita(Milhoes)+" milhoes, " +  Escrita(Mil) + " Mil, " +  Escrita(Reais) + " reais e " + Escrita(Centavos) + " centavos";
        }





        if(Quebras.size() == 5)
        {
            Bilhoes  = Conversao_inteiro(Quebras[0]);
            Milhoes  = Conversao_inteiro(Quebras[1]);
            Mil      = Conversao_inteiro(Quebras[2]);
            Reais    = Conversao_inteiro(Quebras[3]);
            Centavos = Conversao_inteiro(Quebras[4]);


            if((Bilhoes == 1) && (Milhoes == 1) && (Reais == 1))
                aux2 = Escrita(Bilhoes)+ "Bilhao, "+ Escrita(Milhoes)+" milhao, "+  Escrita(Mil) + " Mil, " + Escrita(Reais) + " real e " + Escrita(Centavos) + " centavos";

            else if((Bilhoes == 1) && (Milhoes == 1))
                aux2 = Escrita(Bilhoes)+ "Bilhao, "+ Escrita(Milhoes)+" milhao, "+  Escrita(Mil) + " Mil, " + Escrita(Reais) + " reais e " + Escrita(Centavos) + " centavos";

            else if(Bilhoes == 1)
                aux2 = Escrita(Bilhoes)+ "Bilhao, "+ Escrita(Milhoes)+" milhoes, "+  Escrita(Mil) + " Mil, " + Escrita(Reais) + " reais e " + Escrita(Centavos) + " centavos";

            else
                aux2 = Escrita(Bilhoes)+ "Bilhoes, "+ Escrita(Milhoes)+" milhoes, "+  Escrita(Mil) + " Mil, " + Escrita(Reais) + " reais e " + Escrita(Centavos) + " centavos";
        }

        if(Quebras.size() == 6)
        {
            Trilhoes = Conversao_inteiro(Quebras[0]);
            Bilhoes  = Conversao_inteiro(Quebras[1]);
            Milhoes  = Conversao_inteiro(Quebras[2]);
            Mil      = Conversao_inteiro(Quebras[3]);
            Reais    = Conversao_inteiro(Quebras[4]);
            Centavos = Conversao_inteiro(Quebras[5]);



            if((Trilhoes == 1)  && (Bilhoes == 1) && (Milhoes == 1) && (Reais == 1))
                aux2 = Escrita(Trilhoes)+ " Trilhao, "+ Escrita(Bilhoes)+ " Bilhao, "+ Escrita(Milhoes)+" Milhao, "+  Escrita(Mil) + " Mil, " + Escrita(Reais) + " real e " + Escrita(Centavos) + " centavos";

            else if((Bilhoes == 1) && (Milhoes == 1) && (Reais == 1))
                aux2 = Escrita(Trilhoes)+ " Trilhoes, "+ Escrita(Bilhoes)+ " Bilhao, "+ Escrita(Milhoes)+" Milhao, "+  Escrita(Mil) + " Mil, " + Escrita(Reais) + " real e " + Escrita(Centavos) + " centavos";

            else if((Milhoes == 1) && (Reais == 1))
                aux2 = Escrita(Trilhoes)+ " Trilhoes, "+ Escrita(Bilhoes)+ " Bilhoes, "+ Escrita(Milhoes)+" Milhao, "+  Escrita(Mil) + " Mil, " + Escrita(Reais) + " real e " + Escrita(Centavos) + " centavos";

            else if(Reais == 1)
                aux2 = Escrita(Trilhoes)+ " Trilhoes, "+ Escrita(Bilhoes)+ " Bilhoes, "+ Escrita(Milhoes)+" milhoes, "+  Escrita(Mil) + " Mil, " + Escrita(Reais) + " real e " + Escrita(Centavos) + " centavos";


            if(Trilhoes == 1)
                aux2 = Escrita(Trilhoes)+ " Trilhao, "+ Escrita(Bilhoes)+ " Bilhoes, "+ Escrita(Milhoes)+" milhoes, "+  Escrita(Mil) + " Mil, " + Escrita(Reais) + " reais e " + Escrita(Centavos) + " centavos";

            else
                aux2 = Escrita(Trilhoes)+ " Trilhoes, "+ Escrita(Bilhoes)+ " Bilhoes, "+ Escrita(Milhoes)+" milhoes, "+  Escrita(Mil) + " Mil, " + Escrita(Reais) + " reais e " + Escrita(Centavos) + " centavos";

        }
    }

    Mylist.push_back("Extenso: "+aux2);

}


void Saida()
{
    std::ofstream myfile ("saida.txt");
     if (myfile.is_open())
     {
         for (std::list<std::string>::iterator it = Mylist.begin(); it != Mylist.end(); it++)
             myfile << *it << std::endl;

         myfile.close();
     }
     else
         std::cout << "Nao foi possivel abrir o arquivo";
}


int main()
{
    std::string line;
    std::ifstream myfile ("entrada.txt");
    if (myfile.is_open())
    {
        while (!myfile.eof() )
        {
            getline (myfile,line);
            if(!line.empty())
            {
                if(line.size()<=15)
                {
                    Mylist.push_back("Entrada: "+ line);
                    line = Pontuacao(line);
                    Mylist.push_back("Formatado: "+line);
                    Extenso(line);
                    Saida();
                }
                else
                    std::cout << "String maior que 15"<< std::endl;
            }
        }

        myfile.close();
    }
    else
        std::cout << "O arquivo entrada.txt foi criado?";

    return 0;
}

