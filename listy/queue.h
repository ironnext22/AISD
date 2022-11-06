#ifndef LISTY_QUEUE_H
#define LISTY_QUEUE_H
#include <iostream>
#include <cstdlib>
#define SIZE 1000
template <class T>
class queue
{
private:
    T* arr;
    int capacity;
    T front;
    T back;
    int count;
public:
    queue(int size = SIZE)
    {
      arr = new T[size];
      capacity = size;
      front=0;
      back = -1;
      count = 0;
    }
    ~queue()
    {
        delete[] arr;
    }
    void enqueue(T x)
    {
        if (isFull())
        {
            std::cout << "Overflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        back = (back+1)%capacity;
        arr[back] = x;
        count++;
    }
    T dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
      T x = arr[front];
      front = (front+1)%capacity;
      count--;
        return x;
    }
    T peek()
    {
        if (isEmpty())
        {
            std::cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        return arr[front];
    }
    int size()
    {
        return count;
    }
    bool isEmpty()
    {
        return (size() == 0);
    }
    bool isFull()
    {
        return (size() == capacity);
    }
};
#endif
