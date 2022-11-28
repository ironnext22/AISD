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

    void add(T a){
        node<T>* el= new node<T>;
        node<T> *parent;

        el->key=a;
        el->left=NULL;
        el->right=NULL;

        parent=NULL;

        if(root==NULL) root=el;

        else{
            node<T>*pom;
            pom=root;

            while(pom!=NULL){
                parent=pom;

                if(pom->key>=a) pom=pom->right;
                else pom=pom->left;
            }

            if(parent->key<a) parent->left=el;
            else parent->right=el;
        }

    }

    void inorder(node<T>* el){  //in-order
        if(el!=NULL){
            inorder(el->right);
            cout<<" "<<el->key;
            inorder(el->left);
        }
    }

    void preorder(node<T>* el){  //pre-order
        if(el!=NULL){
            preorder(el->left);
            cout<<" "<<el->data;
            preorder(el->right);
        }
    }
    void display(){
        inorder(root);
    }

    //Usuwanie calego drzewa
    void treedelete(node<T>* el) {
        if (el) {
            treedelete(el->left);
            treedelete(el->right);
            delete el;
        }
    }
    node<T>* find(node<T>* el, int key){
        while(el && el->key != key){
            el = (key > el->key ) ? el->left: el->right;
        }
        return el;
    }
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

    node<T>* del(node<T>* root, int value) {

        if (root == NULL)
            return root;

        if (value > (int) root->key) {
            root->left = del(root->left, value);
        } else if (value < (int) root->key) {
            root->right = del(root->right, value);
        } else {

            if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr)
                return root->left;

            root->key = inOrderSuccessor(root->right);
            root->right = del(root->right, (int) root->key);
        }

        return root;

    }
    int inOrderSuccessor(node<T>* root) {
        int minimum = (int) root->key;
        while (root->left != nullptr) {
            minimum = (int) root->left->key;
            root = root->left;
        }
        return minimum;
    }
};

