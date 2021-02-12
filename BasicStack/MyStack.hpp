#ifndef _MY_STACK_HPP_
#define _MY_STACK_HPP_

#include <list>

template <class T>
class MyStack : private std::list<T>
{
public:
  void push(const T &val);
  void pop();
  const T& top() const;

  bool isEmpty() const;
};

#endif
