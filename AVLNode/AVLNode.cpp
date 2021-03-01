#include "AVLNode.hpp"

#include <iostream>

using namespace std;

AVLNode* rotateWithLeftChild(AVLNode *k2);
AVLNode* rotateWithRightChild(AVLNode *k2);

int getHeight(AVLNode *n)
{
  if (!n) // (n==NULL)
    {
      return 0;
    }
  else
    {
      return n->height();
    }
}

std::ostream&
AVLNode::print(std::ostream &os) const
{
  os << _val
     << " (" << getHeight(_left) << "<->" << getHeight(_right) << ")";
  return os;
}


AVLNode* rotateWithLeftChild(AVLNode *k2)
{
  AVLNode *k1 = k2->left();
  k2->left() = k1->right(); // Y
  k1->right() =  k2;

  k2->height() = 1 + max (k2->left()->height(), k2->right()->height() );
  k1->height() = 1 + max (k1->left()->height(), k2->height() );

  return k1;
}

AVLNode* doubleWithLeftChild(AVLNode *k3)
{
  AVLNode *k1 = k3->left();
  k3->left() = rotateWithRightChild(k1);
  return rotateWithLeftChild(k3);
}

AVLNode* rotateWithRightChild(AVLNode *k2)
{
  AVLNode *k1 = k2->right();
  k2->right() = k1->left(); // Y
  k1->left() =  k2;

  k2->height() = 1 + max (k2->left()->height(), k2->right()->height() );
  k1->height() = 1 + max (k1->left()->height(), k2->height() );

  return k1;
}

AVLNode* doubleWithRightChild(AVLNode *k3)
{
  AVLNode *k1 = k3->right();
  k3->right() = rotateWithLeftChild(k1);
  return rotateWithRightChild(k3);
}



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
      int leftHeight = getHeight(_left);

      int rightHeight = getHeight(_right);

      // might need AVL rotations
      if (leftHeight-rightHeight==2) // imbalance in left
	{
	  // is this a left-left imbalance?
	  if (newVal < intoSubTree->_left->_val )
	    {
	      intoSubTree=rotateWithLeftChild(intoSubTree);
	    }
	  // or is it a left-rght imabalance?
	  else
	    {
	      intoSubTree=doubleWithLeftChild(intoSubTree);
	    }
	}
    }
  else if (newVal > intoSubTree->_val)
    {
      intoSubTree->_right=insert(newVal, intoSubTree->_right);

      // update _height for AVL manipulations
      int leftHeight = getHeight(_left);

      int rightHeight = getHeight(_right);

      // might need AVL rotations
      if (rightHeight-leftHeight==2) // imbalance in right
	{
	  // is this a right-right imbalance?
	  if (newVal >  intoSubTree->_right->_val )
	    {
	      intoSubTree=rotateWithRightChild(intoSubTree);
	    }
	  // or is it a right-left imabalance?
	  else
	    {
	      intoSubTree=doubleWithRightChild(intoSubTree);
	    }
	}

    }
  else // node value already in tree (==)
    {
    }

  intoSubTree->height() = 1 + max(getHeight(intoSubTree->left()),
				  getHeight(intoSubTree->right()) ); 
  
  
  return intoSubTree;
}
