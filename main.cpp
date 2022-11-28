//#include "listy/prezydenci.h"
//#include "listy/nobel.h"
#include "drzewobinarne/tree.h"
void rezerwacja(int minuta,tree<int>& x);
void usunlot(int minuta,tree<int> &x);
int main()
{
    tree<int> x;

    x.add(50);
    x.add(24);
    x.add(50);
    x.add(58);

    x.display();
    cout<<endl;
    rezerwacja(59,x);
    x.display();
   // rezerwacja(4,x);
   // cout<<endl;
   // x.display();

    return 0;
}
void usunlot(int minuta,tree<int> &x){
    node<int>* el;
    for(int i=0;i<minuta;i++)
    {
        x.del(x.root,i);
    }
    // //wezel - do usuniecia
}

void rezerwacja(int minuta,tree<int> &x) {
    time_t czas1;
    time(&czas1);
    struct tm *godzina = localtime(&czas1);
    usunlot(godzina->tm_min,x);
    if (minuta < godzina->tm_min) {
        cout << "Za wczesna rezerwacja" << endl;
        return;
    }

    for(int i=-3; i<4; i++)
    {
        if(x.find(x.root, minuta+i) != nullptr){
            cout<<"Rezerwacja nie moze się odbyc w tej godzinie"<<endl;
            return;
        }
    }
    x.add(minuta);
}

