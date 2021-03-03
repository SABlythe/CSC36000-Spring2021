#ifndef _AVL_TREE_HPP_
#define _AVL_TREE_HPP_

#include "AVLNode.hpp"

#include <iostream>

class AVLTree
{
private:
  AVLNode *_root;
public:
  AVLTree():_root(nullptr) {}

  void insert(int newVal);
  void remove(int val); 

  std::ostream& display(std::ostream &os) const;
};
#endif
