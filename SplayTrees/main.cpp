#include <iostream>

using namespace std;

#include "SplayNode.hpp"
#include "SplayTree.hpp"

int main(int argc, char *argv[])
{
  SplayTree t;

  for (int i=1; i< argc; i++)
    {
      int nextVal=atoi(argv[i]);

      t.insert(nextVal);
      t.display(cout);
      cout << "========" << endl;
    }
  
  cout << "What node should be splayed (-1 to stop)?";
  int rmMe;
  cin >> rmMe;

  while(rmMe!=-1)
    {
      t.lookup(rmMe);

      t.display(cout);
      cout << "========" << endl;
      cout << "What node should be splayed (-1 to stop)?";
      cin >> rmMe;
    }
  
  return 0;
}
