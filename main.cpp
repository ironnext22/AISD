#include <iostream>
#include "lista.h"
int main()
{
    lista<int> x;
    x.addBack(2);
    std::cout<<x[0];
    return 0;
}
