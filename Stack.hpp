#include "LinkedList.hpp"

class Stack : LinkedList
{
    public:
        void push(int value);
        int pop();
        int peek();
        void show();
        bool isEmpty();
        int getLength();
};