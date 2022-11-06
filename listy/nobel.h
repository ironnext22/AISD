#include <iostream>
#include <fstream>
#include <string>
#include "lista.h"
#ifndef LISTY_NOBEL_H
#define LISTY_NOBEL_H
struct nobel
{
    std::string imienazwisko,rok,państwo;
    friend std::ostream& operator<<(std::ostream& st, const nobel& x)
    {
        st<<x.imienazwisko<<" "<<x.rok<<" "<<x.państwo;
        return st;
    }
};
void oddziel(std::string a, std::string& nazwa, std::string& lata, std::string& partia) {
    int spr = 0;
    int liczba = 0;
    for (int i = 0; i < a.length(); i++) {

        if (liczba == 0 && !(a[i] <= 57 && a[i] >= 48)) {
            nazwa += a[i];
        } else {
            if ((a[i] == 45 || (a[i] <= 57 && a[i] >= 48))) {
                lata += a[i];
                liczba++;
            } else {
                partia += a[i];
            }
        }
    }
}
void wczytaj(lista<nobel> &s)
{
    std::fstream plik;
    plik.open("nobel.txt", std::ios::in);
    std::string x;
    nobel temp;
    while(std::getline(plik,x))
    {
        oddziel(x,temp.imienazwisko,temp.rok,temp.państwo);
        s.addBack(temp);
        temp.imienazwisko.clear();
        temp.rok.clear();
        temp.państwo.clear();
    }
}
lista<nobel> kraj(std::string kraj,lista<nobel>& x)
{
    kraj = " "+kraj;
    lista<nobel> y;
    for(int i=0;i<x.size();i++)
    {
        if(x[i].państwo.compare(kraj)==0)y.addBack(x[i]);
    }
    return y;
}
#endif //LISTY_NOBEL_H
