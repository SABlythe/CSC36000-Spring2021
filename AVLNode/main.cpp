#include "AVLTree.hpp"
#include "AVLNode.hpp"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  AVLTree tree;

  for(int i=1; i<argc; i++)
    {
      int valToInsert = atoi(argv[i]);
      tree.insert(valToInsert);
      tree.display(cout);
      cout << "=============" << endl; 
    }

  int delMe;
  cout << "Enter value to delete (-1 to stop):" ;
  cin >> delMe;

  while(delMe != -1)
    {
      tree.remove(delMe);
      tree.display(cout);
      cout << "=============" << endl;
      cout << "Enter value to delete (-1 to stop):" ;
      cin >> delMe;
    }
  
  return 0;
}
