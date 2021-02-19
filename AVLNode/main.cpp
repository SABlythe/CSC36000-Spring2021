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

  return 0;
}
