#ifndef DRZEWOBINARNE_NODE_H
#define DRZEWOBINARNE_NODE_H
template<typename T>
class node
{
public:
    T key;
    node<T>* top;
    node<T>* left;
    node<T>* right;
};
#endif //DRZEWOBINARNE_NODE_H
/*bintree()
{
    if(typeid(X)==typeid(int) ||
       typeid(X)==typeid(float) ||
       typeid(X)==typeid(double))
    {
        root=nullptr;
    }
    else
    {
        std::cout<<"incorrect type";
        delete root;
    }
}*/