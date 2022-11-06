#ifndef DRZEWOBINARNE_BINTREE_H
#define DRZEWOBINARNE_BINTREE_H
#include "node.h"
#include <typeinfo>
#include <iostream>

using namespace  std;

template<typename X>
class bintree{
public:
    node<X>* root;

    bintree(){
        root=NULL;
    }

    void add(X a){
        node<X>* el= new node<X>;   //element, który chcę dodać
        node<X>* parent;            //poprzedni element

        //nadawanie wartosci początkowych
        el->key=a;
        el->left=NULL;
        el->right=NULL;

        parent=NULL;

        if(root==NULL) root=el;     //jesli root nie istnieje to element staje się rootem

        else{                       //jesli element istnieje
            node<X>* pom;            //zmienna pomocnicza
            pom=root;               //nadajemy jej wartosc roota

            while(pom!=NULL){
                parent=pom;

                if(pom->key>=a) pom=pom->right;     //jesli wieksze lub rowne to pom w prawo
                else pom=pom->left;                 // jesli odwrotnie to w lewo
            }

            if(parent->key<a) parent->left=el;
            else parent->right=el;
        }

    }

    void display(node<X>* el){
        if(el!=NULL){
            display(el->left);
            cout<<" "<<el->key;
            display(el->right);
        }
    }
    void dis(){
        display(root);
    }


};
#endif //DRZEWOBINARNE_BINTREE_H
