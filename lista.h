#include "node.h"
#include <iostream>
#ifndef LISTY_LISTA_H
#define LISTY_LISTA_H
template <class X>
class lista {
    node<X> *head;
public:

    lista()
    {
        head = NULL;
    }
    ~lista()
    {
        for(int i = size()-1;i>=0;i--)
        {
            removefront();
        }
    }
    void addFront(X n)
    {
        auto tmp = new node<X>;
        tmp->data = n;
        tmp->next = head;
        head = tmp;

    }
    void addBack(X n)
    {
        auto tmp = new node<X>;
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
    void display()
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
        if(head == nullptr)return;
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
        for(int i = size()-1;i>=0;i--)
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
        if(head == nullptr)return;
        node<X>* tmp = head;
        while(tmp->next->next != nullptr)
        {
            tmp=tmp->next;
        }
        delete tmp->next;
        tmp->next=0;
       // remove(size()-1);
    }
    void removefront()
    {
        if(head == nullptr)return;
        node<X>* temp = head;
        head = temp->next;
        delete temp;
        //remove(0);
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
    void copy(lista<X>* tmp)
    {
        node<X>* x = tmp->head;
        while(x != nullptr)
        {
            addBack(x->data);
            x = x->next;
        }
    }
    explicit lista(lista<X>* tmp)
    {
        head = nullptr;
        node<X>* x = tmp->head;
        while(x != nullptr)
        {
            addBack(x->data);
            x = x->next;
        }
    }
    node<X> clone(X element)
    {
        node<X>* tmp = head;
        auto zw = new node<X>;
        for(int i=0;i<element;i++)
        {
            tmp=tmp->next;
        }
        zw->data = tmp->data;
        return *zw;
    }
};
#endif //LISTY_LISTA_H
