#include <iostream>
#include "lista.h"
int main()
{
    lista<int> x;

    for(int i=0;i<5;i++)
    {
        x.addBack(i);
    }
    //x.Add(3,2);
    std::cout<<x;
    std::cout<<std::endl;
    //x.removeback();
    //x.clear();
    //delete &x;
    lista<int> y(&x);
   // y.copy(&x);
    //std::cout<<x;
    node<int> c = x.clone(3);
    std::cout<<c.data;
    return 0;
}
