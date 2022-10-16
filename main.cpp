#include <iostream>
#include "lista.h"
int main() {
    lista<float> x;
    x.addFront(3.3);
    x.addFront(3.3);
    x.addBack(5.3);
   // x.displey();
    //std::cout<<std::endl;
    //std::cout<<x.size()<<std::endl;
    x.remove(2);
    //std::cout<<std::endl;
   // x.displey();
   // std::cout<<std::endl<<std::endl;
   // //std::cout<<x.size()<<std::endl<<std::endl;
   // x.clear();
    x.addBack(5.3);
    x.addBack(5.3);
   // std::cout<<x[0];
   std::cout<<x;
   //x.displey();
    return 0;
}
