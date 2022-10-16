#include "node.h"
#include <iostream>
#ifndef LISTY_LISTA_H
#define LISTY_LISTA_H
template <class X>
class lista {
    node <X> *head;
public:
    lista()
    {
        head = NULL;
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
        node<X>* tail;
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
        node<X>* tmp = new node<X>;
        tmp->data = n;
        tmp->next = NULL;
        node<X>* c = head;
        while(tmp->next->data!=a)
        {
            c=c->next;
            tmp->next=c->next;
            c->next=head;
        }
    }
    void remove(int nr)
    {
        if(nr==1)
        {
            node<X>* temp = head;
            head = temp->next;
            delete temp;
        }
        else if(nr >= 2)
        {
            int j = 1;
            node<X>* tmp = head;
            while (tmp)
            {
                if ((j+1)==nr) break;
                tmp = tmp->next;
                j++;
            }
            if(tmp->next->next == 0)
            {
                delete tmp->next;
                tmp->next=0;
            }
            else
            {
                node<X> *usuwana = tmp->next;
                tmp->next = tmp->next->next;
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
};
#endif //LISTY_LISTA_H
