#ifndef _AVL_NODE_HPP_
#define _AVL_NODE_HPP_

#include <iostream>

class AVLNode
{
private:
  int _val;
  AVLNode *_left;
  AVLNode *_right;
  int _height;
public:
  AVLNode(int val):_val(val), _left(nullptr), _right(nullptr), _height(1) {}

  AVLNode* left() const {return _left;}
  AVLNode* right() const {return _right;}
  
  std::ostream& print(std::ostream &os) const {os << _val; return os;}

  AVLNode* insert(int newVal, AVLNode *intoSubTree); 

};

#endif
