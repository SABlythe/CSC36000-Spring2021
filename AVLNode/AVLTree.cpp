#include "AVLTree.hpp"

#include <iostream>

using namespace std;

void
AVLTree::insert(int newVal)
{
  if (!_root)
    _root = new AVLNode(newVal);
  _root = _root->insert(newVal, _root);
}

int depth;

void helper(ostream &os, AVLNode *node)
{
  if (!node) return;

  depth++;
  helper(os, node->right());
  depth--;

  for (int i=0; i<depth; i++)
    os << "    ";
  
  node->print(os);
  os << endl;

  depth++;
  helper(os, node->left());
  depth--;
  
}

ostream& 
AVLTree::display(ostream &os) const
{
  depth=0;
  helper(os, _root);
  return os; 
}
