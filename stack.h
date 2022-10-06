#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack  : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template<typename T>
Stack<T>::Stack() 
{

}

template<typename T>
Stack<T>::~Stack() 
{
  
}

template <typename T>
bool Stack<T>::empty() const
{
  // vector has a empty() function
  return static_cast<std::vector<T>*>(this)->empty();
}

template <typename T>
size_t Stack<T>::size() const
{
  //vector has a size function
  return static_cast<std::vector<T>*>(this)->size();
}

template <typename T>
void Stack<T>::push(const T& item)
{
  static_cast<std::vector<T>*>(this)->push_back(item);
}

template <typename T>
void Stack<T>::pop()
{
  if (empty())
  {
    throw std::underflow_error("stack is empty");
  }
  static_cast<std::vector<T>*>(this)->pop_back();
}

template <typename T>
const T& Stack<T>::top() const
{
  if (empty())
  {
    throw std::underflow_error("stack is empty");
  }
  
  return static_cast<std::vector<T>*>(this)->back();
}



#endif