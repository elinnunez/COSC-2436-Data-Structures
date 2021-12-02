#include "Node.h"

class EmptyStackException {}; //throw error

template <typename T>
class Stack
{
private:
  Node<T> *top;

public:
  Stack();
  bool const empty();
  void push(T val);
  T const peek();
  void pop();
};

template <typename T>
Stack<T>::Stack()
{
  top = nullptr;
}

template <typename T>
bool const Stack<T>::empty()
{
  return top == nullptr;
}

template <typename T>
void Stack<T>::push(T val)
{
  Node<T> *temp = new Node<T>;
  temp->value = val;
  temp->next = top;
  top = temp;
}

template <typename T>
T const Stack<T>::peek()
{
  //use throw/exception
  if (empty())
  {
    std::cout << "Empty list" << std::endl;
    throw EmptyStackException();
  }
  else
  {
    return top->value;
  }
}

template <typename T>
void Stack<T>::pop()
{
  //throw exception
  if (empty())
  {
    std::cout << "Empty" << std::endl;
    throw EmptyStackException();
  }
  else
  {
    Node<T> *temp = top;
    top = temp->next;
    delete temp;
  }
}