#include <iostream>
#include <fstream>
#include <string>
#include "lista.h"
#ifndef LISTY_PREZYDENCI_H
#define LISTY_PREZYDENCI_H
struct Prezydenci
{
    std::string imie,nazwisko,lata,partia;
    friend std::ostream& operator<<(std::ostream& st, const Prezydenci& x)
    {
        st<<x.imie<<" "<<x.nazwisko<<" "<<x.lata<<" "<<x.partia;
        return st;
    }
};
void wczytaj(lista<Prezydenci> &s)
{
    std::fstream plik;
    plik.open("presidents.txt",std::ios::in);
    std::string x;
    Prezydenci temp;
    while(std::getline(plik,x))
    {
        for(int j=0;j<4;j++)
        {
            int p = x.find_first_of(" ")+1;
            if(p==0)p=x.length();
            std::string tekst;
            if(x[p+1]=='.')p++;
            for (int i = 0; i < p; i++) {
                tekst.push_back(x[i]);

            }
            if(x[p]=='.')tekst.push_back('.');
            else tekst.pop_back();
            if(x[p]=='.')x.erase(0,p+2);
            else x.erase(0,p);
            if(j==0)temp.imie=tekst;
            if(j==1)temp.nazwisko=tekst;
            if(j==2)temp.lata=tekst;
            if(j==3)temp.partia=tekst;
        }
        s.addBack(temp);
    }
    plik.close();
}
lista<Prezydenci> Pmin(lista<Prezydenci>& x)
{
lista<Prezydenci> y;
int min;
for(int i=0;i<x.size();i++)
{

    std::string tekst,t1,t2;
    tekst=x[i].lata;
    int p = tekst.find_first_of("-") + 1;
    for(int j=0;j<p-1;j++)
    {
        t1.push_back(tekst[j]);
    }
    tekst.erase(0,p);
    t2=tekst;
    int l1,l2;
    l1= std::stoi(t1);
    l2= std::stoi(t2);
    int lata = l2-l1;
    if(lata<0)x.remove(i);
    else
    {
        if(i==0)min=lata;
        else if(lata<min)min=lata;
    }
}
    for(int i=0;i<x.size();i++)
    {

        std::string tekst, t1, t2;
        tekst = x[i].lata;
        int p = tekst.find_first_of("-") + 1;
        for (int j = 0; j < p - 1; j++) {
            t1.push_back(tekst[j]);
        }
        tekst.erase(0, p);
        t2 = tekst;
        int l1, l2;
        l1= std::stoi(t1);
        l2= std::stoi(t2);
        int lata = l2-l1;
        if(lata==min)y.addBack(x[i]);
    }
    return y;
}
lista<Prezydenci> Part(lista<Prezydenci>& x,std::string partia)
{
    lista<Prezydenci> y;
    {    for(int i=0;i<x.size();i++)

            if(partia.compare(x[i].partia)==1)
        {
            y.addBack(x[i]);
        }
    }
    return y;
}
lista<Prezydenci> Rok(lista<Prezydenci>& x, int rok)
{
    lista<Prezydenci> y;
    for(int i=0;i<x.size();i++)
    {

        std::string tekst, t1, t2;
        tekst = x[i].lata;
        int p = tekst.find_first_of("-") + 1;
        for (int j = 0; j < p - 1; j++) {
            t1.push_back(tekst[j]);
        }
        tekst.erase(0, p);
        t2 = tekst;
        int l1, l2;
        l1 = std::stoi(t1);
        l2 = std::stoi(t2);
        if(rok>=l1 && rok<=l2)y.addBack(x[i]);
    }
    return y;
}
#endif //LISTY_PREZYDENCI_H
