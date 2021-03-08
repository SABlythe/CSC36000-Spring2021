#ifndef _AVL_NODE_HPP_
#define _AVL_NODE_HPP_

#include <iostream>


class SplayNode
{
private:
  int _val;
  SplayNode *_left;
  SplayNode *_right;
public:
  SplayNode(int val)
    : _val(val), _left(nullptr), _right(nullptr) {}

  std::ostream& print(std::ostream &os) const;

  const int value() const {return _val;}
  int & value() {return _val;}

  const SplayNode* left() const {return _left;}
  SplayNode* & left() {return _left;}

  const SplayNode* right() const {return _right;}
  SplayNode* & right() {return _right;}

  bool isLeaf() const { return !_left&&!_right; }
  
  SplayNode* insert(int newVal, SplayNode *intoSubTree);

  SplayNode* remove(int existingVal, SplayNode *fromSubTree);

  SplayNode* lookup(int val, SplayNode *subTree);
  
  friend std::ostream& operator<<(std::ostream &os, const SplayNode &n);
};


#endif
