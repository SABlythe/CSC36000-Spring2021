#include "AVLNode.hpp"

#include <iostream>

using namespace std;


AVLNode*
AVLNode::insert(int newVal, AVLNode *intoSubTree)
{
  if (intoSubTree==nullptr)
    {
      AVLNode *newRoot = new AVLNode(newVal);
      return newRoot;
    }

  else if (newVal < intoSubTree->_val)
    {
      intoSubTree->_left=insert(newVal, intoSubTree->_left);

      // update _height for AVL manipulations

      // might need AVL rotations
    }
  else if (newVal > intoSubTree->_val)
    {
      intoSubTree->_right=insert(newVal, intoSubTree->_right);

      // update _height for AVL manipulations

      // might need AVL rotations
    }
  else // node value already in tree (==)
    {
    }

  return intoSubTree;
}
