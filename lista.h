#include "node.h"
#include <iostream>
#ifndef LISTY_LISTA_H
#define LISTY_LISTA_H
template <class X>
class lista {
    node<X> *head;
public:
    lista() {
        head = NULL;
    }

    ~lista()
    {
        delete head;
    }
    void addFront(X n)
    {
        node<X>* tmp = new node<X>;
        tmp->data = n;
        tmp->next = head;
        head = tmp;

    }
    void addBack(X n)
    {
        node<X>* tmp = new node<X>;
        tmp->data = n;
        tmp->next = NULL;
        if(!head)
        {
            head=tmp;
            return;
        }
        node<X>* tail = head;
        while(tail->next!= NULL)
        {
            tail=tail->next;
        }
        tail->next=tmp;
    }
    void displey()
    {
        node<X>* tmp = head;
        while(tmp != nullptr)
        {
            std::cout<<tmp->data<<std::endl;
            tmp = tmp->next;
        }
    }
    void Add(X n,int a)
    {
        if(a>size())return;
        else if(a==0)addFront(n);
        else
        {
            node<X>* tmp = head;
            for(int i=1;i<a;i++)
            {
                tmp = tmp->next;
            }
            node<X>* x = tmp->next;
            node<X> od;
            tmp->next = &od;
            od.next = x;
            od.data=n;
        }
    }
    void remove(int nr)
    {
        if(nr==0)
        {
            node<X>* temp = head;
            head = temp->next;
            delete temp;
        }
        else if(nr >= 1)
        {
            node<X>* tmp = head;
            node<X>* t2m = head->next->next;
            for(int j=1;j<nr;j++)
            {
                tmp = tmp->next;
                t2m = t2m->next;
            }
            if(t2m == nullptr)
            {
                delete tmp->next;
                tmp->next=0;
            }
            else
            {
                node<X> *usuwana = tmp->next;
                tmp->next = t2m;
                delete usuwana;
            }
        }
    }
    int size()
    {
        int i=0;
        node<X>* tmp = head;
        if(head == NULL)return i;
        else {
            do {
                tmp = tmp->next;
                i++;
            } while (tmp != NULL);
        }
        return i;
    }
    void clear()
    {
        for(int i = size();i>0;i--)
        {
            remove(i);
        }
    }
    X operator[ ](int liczba)
    {
        node<X>* tail = head;
        X tmp;
        for(int i=0;i<=liczba;i++)
        {
            tmp = tail->data;
            tail = tail->next;
        }
        return tmp;
    }
    bool empty()
    {
        if(head == nullptr)return true;
        else return false;
    }
    void removeback()
    {
        remove(size()-1);
    }
    void removefront()
    {
        remove(0);
    }
    friend std::ostream& operator<<(std::ostream& st, const lista<X>& x)
    {
        node<X>* tmp = x.head;
        while(tmp != nullptr)
        {
            st<<tmp->data<<std::endl;
            tmp = tmp->next;
        }
        return st;
    }
};
#endif //LISTY_LISTA_H
