#ifndef _AVL_TREE_HPP_
#define _AVL_TREE_HPP_

#include <iostream>

#include "SplayNode.hpp"

class SplayTree
{
private:
  SplayNode *_root;
public:
  SplayTree(): _root(nullptr) {}

  std::ostream& display(std::ostream &os) const;

  void insert(int newVal) {if (!_root) _root=new SplayNode(newVal); else _root=_root->insert(newVal, _root);} 

  void remove(int val) {_root=_root->remove(val, _root);}

  void lookup(int val) {_root=_root->lookup(val, _root);}
};

#endif
