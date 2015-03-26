#ifndef LEITOR_H
#define LEITOR_H

#include <string>
#include <vector>
#include <sstream>
#include <list>

std::list <std::string> Mylist;


std::string formataReal(double dv)

{
    const std::string Centavos = ",";
    const std::string Milhar = ".";
    const std::string Unidade = "R$ ";

    unsigned long v = (unsigned long) ((dv * 100.0) + .5);

    std::string fmt,digit;

    int i = -2;
    do {

        if(i == 0) {

            fmt = Centavos + fmt;

        }

        if((i > 0) && (!(i % 3))) {

            fmt = Milhar + fmt;

        }

        digit = (v % 10) + '0';

        fmt = digit + fmt;

        v /= 10;

        i++;

    }

    while((v) || (i < 1));

    std::string rv;

    rv = Unidade + fmt;

    return rv;

}



void replace_str(std::string& str, const std::string de,const std::string para)
{
    int i = 0, loc;

    if(str.empty()){
        str = de;
        return;
    }

    while(i < str.size()){
        loc = str.find(de, 0);

        if(loc >= 0)
            str.replace(loc, de.length(), para);
        else
            return;

        i++;
    }
}


void separar(const std::string& str, char delim,std::vector<std::string>& pedacos){
    std::string::size_type i = 0;
    std::string::size_type j = str.find(delim);

    while(j != std::string::npos){
        pedacos.push_back(str.substr(i, j - i));
        i = ++j;
        j = str.find(delim, j);

        if(j == std::string::npos)
            pedacos.push_back(str.substr(i, str.length()));
    }
}


int Conversao_inteiro(std::string Dinheiro)
{
    unsigned int Valor_Total;

    std::stringstream ss(Dinheiro);
    ss >> Valor_Total;
    return Valor_Total;
}

std::string Escrita(int Valor)
{
    int Dezena, Unidade;
    std::string Total;

    if (Valor >= 900)
    {
        if (Valor == 900)
            Total =  "Novecentos";
        else
            Total =  "Novecentos e ";
    }
    else if (Valor >= 800 )
    {
        if (Valor == 800)
            Total =  "Oitocentos";
        else
            Total =  "Oitocentos e ";
    }
    else if (Valor >= 700 )
    {
        if (Valor == 700)
            Total =  "Setecentos";
        else
            Total =  "Setecentos e ";
    }
    else if (Valor >= 600 )
    {
        if (Valor == 600)
            Total =  "Seiscentos";
        else
            Total =  "Seiscentos e ";
    }
    else if (Valor >= 500 )
    {
        if (Valor == 500)
            Total =  "Quinhentos";
        else
            Total =  "Quinhentos e ";
    }
    else if (Valor >= 400 )
    {
        if (Valor == 400)
            Total =  "Quatrocentos";
        else
            Total =  "Quatrocentos e ";
    }
    else if (Valor >= 300 )
    {
        if (Valor == 300)
            Total =  "Trezentos";
        else
            Total =  "Trezentos e ";
    }
    else if (Valor >= 200 )
    {
        if (Valor == 200)
            Total =  "Duzentos";
        else
            Total =  "Duzentos e ";
    }
    else if (Valor >= 100)
    {
        if (Valor == 100)
            Total =  "Cem";
        else
            Total =  "Cento e ";
    }

    Dezena = Valor % 100;

    if (Dezena >= 90)
    {
        if (Dezena == 90 )
            Total =  Total + "Noventa";
        else
            Total =  Total + "Noventa e ";
    }
    else if (Dezena >= 80 )
    {
        if (Dezena == 80 )
            Total =  Total + "Oitenta";
        else
            Total =  Total + "Oitenta e ";
    }
    else if (Dezena >= 70)
    {
        if (Dezena == 70 )
            Total =  Total + "Setenta";
        else
            Total =  Total + "Setenta e ";
    }
    else if (Dezena >= 60 )
    {
        if (Dezena == 60)
            Total =  Total + "Sessenta";
        else
            Total =  Total + "Sessenta e ";
    }
    else if (Dezena >= 50 )
    {
        if (Dezena == 50 )
            Total =  Total + "Cinquenta";
        else
            Total =  Total + "Cinquenta e ";
    }
    else if (Dezena >= 40 )
    {
        if (Dezena == 40)
            Total =  Total + "Quarenta";
        else
            Total =  Total + "Quarenta e ";
    }
    else if (Dezena >= 30)
    {
        if (Dezena == 30)
            Total =  Total + "Trinta";
        else
            Total =  Total + "Trinta e ";
    }
    else if (Dezena >= 20 )
    {
        if (Dezena == 20)
            Total =  Total + "Vinte";
        else
            Total =  Total + "Vinte e ";
    }




    if (Dezena > 10 && Dezena < 20)
        Unidade = Dezena % 20;
    else
        Unidade = Dezena % 10;

    if (Unidade)
    {
        switch (Unidade)
        {
        case 19:
            Total =  Total + "Dezenove";
            break;
        case 18:
            Total =  Total + "Dezoito";
            break;
        case 17:
            Total =  Total + "Dezessete";
            break;
        case 16:
            Total =  Total + "Dezesseis";
            break;
        case 15:
            Total =  Total + "Quinze";
            break;
        case 14:
            Total =  Total + "Quatorze";
            break;
        case 13:
            Total =  Total + "Treze";
            break;
        case 12:
            Total =  Total + "Doze";
            break;
        case 11:
            Total =  Total + "Onze";
            break;
        case 10:
            Total =  Total + "Dez";
            break;
        case 9:
            Total =  Total + "Nove";
            break;
        case 8:
            Total =  Total + "Oito";
            break;
        case 7:
            Total =  Total + "Sete";
            break;
        case 6:
            Total =  Total + "Seis";
            break;
        case 5:
            Total =  Total + "Cinco";
            break;
        case 4:
            Total =  Total + "Quatro";
            break;
        case 3:
            Total =  Total + "Tres";
            break;
        case 2:
            Total =  Total + "Dois";
            break;
        case 1:
            Total =  Total + "Um";
            break;
        }
    }


    return Total;


}





#endif // LEITOR_H

