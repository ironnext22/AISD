//#include "prezydenci.h"
#include "nobel.h"
int main()
{
    lista<nobel> x;
   // lista<Prezydenci> listaa;
   // wczytaj(listaa);
   // std::cout<<Pmin(listaa)<<std::endl;
   // std::cout<<Part(listaa,"Democratic")<<std::endl;
   // std::cout<<Rok(listaa,1801)<<std::endl;
    wczytaj(x);
    std::cout<<x<<std::endl<<std::endl;
    std::cout<<kraj("Francja",x);
    return 0;
}
