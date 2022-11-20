#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "node.h"

using namespace  std;

template<typename T>
class tree{
public:
    node<T>* root;

    tree(){
        root=NULL;
    }

    //--------------------------------//
    //Dodawanie elmentu do drzewa
    void add(T a){
        node<T>* el= new node<T>;   //element, który chcę dodać
        node<T> *parent;            //poprzedni element

        //nadawanie wartosci początkowych
        el->key=a;
        el->left=NULL;
        el->right=NULL;

        parent=NULL;

        if(root==NULL) root=el;     //jesli root nie istnieje to element staje się rootem

        else{                       //jesli element istnieje
            node<T>*pom;            //zmienna pomocnicza
            pom=root;               //nadajemy jej wartosc roota

            while(pom!=NULL){
                parent=pom;

                if(pom->key>=a) pom=pom->right;     //jesli wieksze lub rowne to pom w prawo
                else pom=pom->left;                 // jesli odwrotnie to w lewo
            }

            if(parent->key<a) parent->left=el;      //jesli mniejsze to poprzedni element w lewo
            else parent->right=el;                  // jesli odwrotnie to w prawo
        }

    }

    //--------------------------------//
    //Wypisywanie drzewa

    //rosnąco
    void inorder(node<T>* el){  //in-order
        if(el!=NULL){
            inorder(el->right);
            cout<<" "<<el->key;
            inorder(el->left);
        }
    }

    //malejąco
    void preorder(node<T>* el){  //pre-order
        if(el!=NULL){
            preorder(el->left);
            cout<<" "<<el->key;
            preorder(el->right);
        }
    }
    void display(){
        inorder(root);
    }

    //--------------------------------//
    //Usuwanie calego drzewa
    void treedelete(node<T>* el) {
        if (el) {
            treedelete(el->left);
            treedelete(el->right);
            delete el;
        }
    }

    //Usuwanie pojedynczego wezla
    node<T>* remove(int x, node<T>* t)
    {
        node<T>* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->key)
            t->left = remove(x, t->left);
        else if(x > t->key)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = minmaxkey(t->right,true);
            t->key = temp->key;
            t->right = remove(t->key, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        return t;
    }
    void remove(int x)
    {
        root = remove(x, root);
    }

    //--------------------------------//
    //Wyszukiwanie węzła w drzewie
    node<T>* find(node<T>* el, int key){
        while(el && el->key != key){
            el = (key < el->key ) ? el->left: el->right;
        }
        return el;
    }

    //Wyszukiwanie następcy
    node<T>* nast(node<T>* el){
        node<T>* pom;

        if(el){
            if(el->right) return minmaxkey(el->right,true);

            else{
                pom=el->top;
                while(pom && (el == pom->right)){
                    el= pom;
                    pom = pom->top;
                }
                return pom;
            }

        }
        return el;
    }

    //Wyszukiwanie poprzednika
    node<T>* poprz(node<T>* el){
        node<T>* pom;

        if(el){
            if(el->left) return minmaxkey(el->left,false);

            else{
                pom=el->top;
                while(pom && (el == pom->left)){
                    el= pom;
                    pom = pom->top;
                }
                return pom;
            }

        }
        return el;
    }

    //Wyszukiwanie węzla o najmniejszym/wiekszym kluczu
    node<T>* minmaxkey ( node<T>* el, bool a )
    {
        if(a==true){
            if( el ) while( el->left ) el = el->left;
            return el;
        }
        else{
            if( el ) while( el->right ) el = el->right;
            return el;
        }
    }

};
