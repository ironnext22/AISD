//#include "listy/prezydenci.h"
//#include "listy/nobel.h"
#include "drzewobinarne/tree.h"
void rezerwacja(int minuta,tree<int>& x);
void usunlot(int minuta,tree<int> &x);
int main()
{
    tree<int> x;

    x.add(20);
    x.add(47);
    x.add(50);
    x.add(58);

    x.display();
    cout<<endl;
    rezerwacja(4,x);
    cout<<endl;
    x.display();

    return 0;
}
