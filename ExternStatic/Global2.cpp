#include <iostream>

void printMe1();


using namespace std;

static int globalVar=42;

void printMe2()
{
  cout << globalVar << endl;
}

int main(int argc, char *argv[])
{
  printMe1();
  printMe2();

  return 0;
}
