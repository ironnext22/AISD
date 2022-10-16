#include <iostream>
#include "lista.h"
int main()
{
    lista<int> x;
    for(int i=0;i<5;i++)
    {
        x.addBack(i);
    }
    x.Add(3,2);
    std::cout<<x;
    return 0;
}
