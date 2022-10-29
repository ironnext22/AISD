#include <iostream>
#include "lista.h"
#include <fstream>
#include <set>
struct utwory
{
    std::string miejsce,zespol,tytul,rok,n1,n2,n3;
    friend std::ostream& operator<<(std::ostream& st, const utwory& x)
    {
        st<<x.miejsce<<" "<<x.zespol<<" "<<x.tytul<<" "<<x.rok<<" "<<x.n1<<" "<<x.n2<<" "<<x.n3;
        return st;
    }
};
void wczytaj(lista<utwory> &s)
{
        std::fstream plik;
        plik.open("Grupa3.txt",std::ios::in);
        std::string x;
        utwory temp;
        while(std::getline(plik,x))
        {
            for(int j=0;j<7;j++)
            {
                int p = x.find_first_of(",")+1;
                if(p==0)p=x.length()+1;
                std::string tekst;
                for (int i = 0; i < p-1; i++) {
                    tekst.push_back(x[i]);

                }
                x.erase(0,p+1);
                if(j==0)temp.miejsce=tekst;
                if(j==1)temp.zespol=tekst;
                if(j==2)temp.tytul=tekst;
                if(j==3)temp.rok=tekst;
                if(j==4)temp.n1=tekst;
                if(j==5)temp.n2=tekst;
                if(j==6)temp.n3=tekst;
            }
            s.addBack(temp);
        }
        plik.close();
}
lista<utwory> podrok(lista<utwory> &x,int rok) // zadanie 2
{
    lista<utwory> y;
    for(int i=0;i<x.size();i++)
    {
        int c;
        std::string tekst = x[i].rok;
        c=std::stoi(tekst);
        if(c==rok)y.addBack(x[i]);
    }
    return y;
}
bool wykonawcatoautor(lista<utwory> &x,int pos) //zadanie 3
{
    if(x[pos].n1.compare(x[pos].zespol)==0)return true;
    else if(x[pos].n2.compare(x[pos].zespol)==0) return true;
    else if(x[pos].n3.compare(x[pos].zespol)==0) return true;
    else return false;
}
void wykonpos(lista<utwory> &x,int pos)
{
    std::cout<<"Czy wykonawca piosenki nr. "<<pos<<" to tez jej autor: ";
    pos=50-pos;
    if(wykonawcatoautor(x,pos)== true)std::cout<<"tak"<<std::endl;
    else std::cout<<"nie"<<std::endl;
}
lista<std::string> wykonawca2razy(lista<utwory> &x) //zadanie 1;
{
    lista<utwory> y;
    lista<std::string> z;
    std::set<std::string> k;
    for(int i=0;i<x.size();i++)
    {
        for (int j = 0; j < x.size(); j++)
        {
            if (x[i].n1.compare(x[j].zespol) == 0)y.addBack(x[i]);
        }
        if (y.size() > 1)k.insert(x[i].zespol);
        y.clear();
    }
    for(auto x : k)
    {
        z.addBack(x);
    }
    return z;
}
int main() {
    lista<utwory> x;
    wczytaj(x);
    std::cout<<"zadanie 1:"<<std::endl;
    std::cout<<wykonawca2razy(x)<<std::endl;
    std::cout<<"zadanie 2:"<<std::endl;
    std::cout<<podrok(x,1965)<<std::endl;
    std::cout<<"zadanie 3:"<<std::endl;
    wykonpos(x,37);
    std::cout<<std::endl;

    return 0;
}
