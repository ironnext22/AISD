#include <iostream>
#include "lista.h"
int main()
{
    lista<int> x;
    lista<int> y;
    for(int i=0;i<5;i++)
    {
        x.addBack(i);
    }
    //x.Add(3,2);
    std::cout<<x;
    std::cout<<std::endl;
    y.copy(&x);
    std::cout<<y;
    return 0;
}
