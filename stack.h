#ifndef LISTY_STACK_H
#define LISTY_STACK_H
template<class T>
class stack
{
    T* arr;
    int top;
    int capacity;
public:
    stack(int size = 1000)
    {
        arr = new T[size];
        capacity = size;
        top = -1;
    }
    ~stack()
    {
        delete[] arr;
    }
    void push(T x)
    {

    }
};
#endif //LISTY_STACK_H
