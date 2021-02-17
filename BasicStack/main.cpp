#include <iostream>

#include "MyStack.hpp"
#include "MyStack.ctt"

using namespace std;

int main(int argc, char *argv[])
{
  MyStack<int> numbers;
 
  numbers.push(42);
  numbers.push(102);

  numbers.push(36000);

  cout << numbers.top() << endl;
  cout << numbers.top() << endl;

  numbers.pop();

  cout << numbers.top() << endl;

  cout << "=======" << endl;

  while(!numbers.isEmpty())
    {
      cout << numbers.top() << endl;
      numbers.pop();
    }
   
  cout << "=======" << endl;

  cout << numbers.top();

  numbers.pop();
  
  return 0;
}
