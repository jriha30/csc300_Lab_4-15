#include "Stack.hpp"

void Stack::push(int value)
{
    this->addFront(value);
}

void Stack::show()
{
    this->display();
}

bool Stack::isEmpty()
{
    return this->count == 0;
}

int Stack::getLength()
{
    return this->count;
}

int Stack::pop()
{
    return this->removeFront();
}

int Stack::peek()
{
    return this->getNodeAtIndex(0)->getPayload();
}