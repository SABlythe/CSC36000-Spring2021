#include "MyStack.hpp"

using namespace std;

template <class X>
void
MyStack<X>::push(const X& somethingToPush)
{
  list<X>::push_front(somethingToPush);
}
