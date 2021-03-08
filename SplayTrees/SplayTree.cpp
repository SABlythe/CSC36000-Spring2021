#include "SplayTree.hpp"

using namespace std;


int depth=0;

void helper(ostream &os, const SplayNode* node)
{
  if (!node) return;

  depth++;
  helper(os, node->right());
  depth--;

  for (int i=0; i< depth; i++)
    os << "    ";


  os << *node << endl;

  depth++;
  helper(os, node->left());
  depth--;
}

ostream&
SplayTree::display(ostream &os) const
{
  depth=0;
  helper(os, _root);
  return os;
}
