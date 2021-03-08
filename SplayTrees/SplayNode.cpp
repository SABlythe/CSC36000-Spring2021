#include "SplayNode.hpp"

#include <iostream>

using namespace std;
extern void helper(ostream &os, const SplayNode* node);

/*
int getHeight(const SplayNode *node)
{
  if (node==nullptr)
    return 0;
  else
    return node->height();
}
*/


SplayNode* rotateWithLeftChild(SplayNode *k2)
{
  SplayNode *k1 = k2->left();
  k2->left() = k1->right();  // Y
  k1->right() = k2;
  //k2->height() = 1+ max(getHeight(k2->left()), getHeight(k2->right()) );
  //k1->height() = 1+ max(getHeight(k1->left()), getHeight(k2) );
  return k1;
}

SplayNode* rotateWithRightChild(SplayNode *k2)
{
  SplayNode *k1 = k2->right();
  k2->right() = k1->left();  // Y
  k1->left() = k2;
  //k2->height() = 1+ max(getHeight(k2->left()), getHeight(k2->right()) );
  //k1->height() = 1+ max(getHeight(k1->right()), getHeight(k2) );
  return k1;
}

SplayNode* doubleWithLeftChild(SplayNode *k3)
{
   SplayNode *k1 = k3->left();
   k3->left() = rotateWithRightChild( k1 );
   return rotateWithLeftChild( k3 );
}

SplayNode* doubleWithRightChild(SplayNode *k3)
{
   SplayNode *k1 = k3->right();
   k3->right() = rotateWithLeftChild( k1 );
   return rotateWithRightChild( k3 );
}



SplayNode*
SplayNode::insert(int val, SplayNode *intoSubTree)
{
  if (intoSubTree==nullptr)
    return new SplayNode(val);
  else if (val < intoSubTree->_val)
    {
      intoSubTree->_left=insert(val, intoSubTree->_left);

      /*
      int leftHeight=intoSubTree->_left->_height;
      int rightHeight=0;
      if (intoSubTree->_right!=nullptr)
	rightHeight=intoSubTree->_right->_height;
      
      if (leftHeight-rightHeight==2)
	{
	  if (val < intoSubTree->left()->value() )
	    {
	      intoSubTree = rotateWithLeftChild(intoSubTree); //case 1
	    }
	  else
            intoSubTree = doubleWithLeftChild(intoSubTree); // case 2
	}
      */
    }
  else if (val > intoSubTree->_val)
    {
      intoSubTree->_right=insert(val, intoSubTree->_right);

      /*
      int rightHeight=intoSubTree->_right->_height;
      int leftHeight=0;
      if (intoSubTree->_left!=nullptr)
	leftHeight=intoSubTree->_left->_height;

      if (rightHeight - leftHeight ==2)
	{
	  if (val > intoSubTree->right()->value() )
	    {
	      intoSubTree = rotateWithRightChild(intoSubTree); //case 4
	    }
	  else
	    intoSubTree = doubleWithRightChild(intoSubTree); // case 3
	}
      */
    }
  else // equal
    ;

  /*
  intoSubTree->height() = 1+max( getHeight(intoSubTree->left()),
				 getHeight(intoSubTree->right()) );
  */
  return intoSubTree;
}

SplayNode*
SplayNode::remove(int existingVal, SplayNode *fromSubTree)
{
  // existingVal not found!
  if (fromSubTree==nullptr)
    return NULL;
  
  if (existingVal>fromSubTree->value())
    {
      fromSubTree->right() = remove(existingVal, fromSubTree->right());
    }


  else if (existingVal<fromSubTree->value())
    {
      fromSubTree->left() = remove(existingVal, fromSubTree->left());
    }

  else
    {
      // if we get here, we've found the node to delete. Three cases:
      // 1. we are a leaf node.
      if (fromSubTree->isLeaf())
	{
	  fromSubTree=nullptr;
	}
      // 2. we have two children.
      else if (fromSubTree->left() && fromSubTree->right() )
	{
	  // go left, then as far right as we can.
	  SplayNode *toDel = fromSubTree->left();
	  while(toDel->right())
	    toDel=toDel->right();

	  int val = toDel->value();
	  fromSubTree->left()=fromSubTree->remove(val, fromSubTree->left());
	  fromSubTree->value()=val;
	}
      // 3. we have one child.
      else
	{
	  if (fromSubTree->left())
	    fromSubTree=fromSubTree->left();
	  else //if (fromSubTree->right())
	    fromSubTree=fromSubTree->right();
	}
      
    }

  /*
  // now rotate this node if need be ...

  // if this was a deleted leaf node, then we don't need to do anything
  if (!fromSubTree)
    return fromSubTree;

  // otherwise, we are not a leaf node and have children to deal with
  int balance = getHeight(fromSubTree->left()) -
                getHeight(fromSubTree->right());

  // if we have a left issue ...
  if (balance==2)
    {
      // get balance of left child
      int subBalance = getHeight(fromSubTree->left()->left()) -
	               getHeight(fromSubTree->left()->right());

      // left-left issue
      if (subBalance>=0)
	{
	  fromSubTree = rotateWithLeftChild(fromSubTree);
	}
      else //left-right issue
	{
	  fromSubTree = doubleWithLeftChild(fromSubTree);
	}
    }

  // if we have a right issue
  if (balance==-2)
    {
      // get balance of right child
      int subBalance = getHeight(fromSubTree->right()->left()) -
	               getHeight(fromSubTree->right()->right());

      // right-right issue
      if (subBalance<0)
	{
	  fromSubTree = rotateWithRightChild(fromSubTree);
	}
      else //right-left issue
	{
	  fromSubTree = doubleWithRightChild(fromSubTree);
	}
      
    }


  fromSubTree->_height = 1+max( getHeight(fromSubTree->left()),
			        getHeight(fromSubTree->right()) );
  */
  return fromSubTree; 
}


extern void helper(ostream &os, const SplayNode* node);
  
SplayNode*
SplayNode::lookup(int val, SplayNode *subTree)
{
  if (subTree==nullptr)
    return nullptr;

  cout << "looking up " << val << " @ " << subTree->value() << endl;
  
  if (subTree->value()==val)
    return subTree;

  // check left child
  if (val<subTree->value())
    {
      if (!subTree->left())
	return subTree;
      
      // LL case
      if (val < subTree->left()->value())
	{
	  // recursively bring val to root of left-left
	  subTree->left()->left()=lookup( val, subTree->left()->left() );
	  
	  // now rotate the current root right
	  subTree=rotateWithLeftChild(subTree);
	  
	  //note: second rotation is below (common for LL and LR case)
	}
      else if  (val > subTree->left()->value())
	{
	  // recursively bring val to root of left-right
	  subTree->left()->right()=lookup( val, subTree->left()->right() );
	  
	  // if exists, do first step of RL (second is below)
	  if (subTree->left()->right())
	    subTree->left() = rotateWithRightChild(subTree->left());
	}
      
      if (!subTree->left())
	return subTree;
      else
	return rotateWithLeftChild(subTree);
    }
  // check right child
  else // val>subTree->value()
    {
      if (!subTree->right())
	return subTree;
      
      // RR case
      if (val > subTree->right()->value())
	{
	  // recursively bring val to root of right-right
	  subTree->right()->right()=lookup( val, subTree->right()->right() );
	  
	  // now rotate the current root left
	  subTree=rotateWithRightChild(subTree);
	  
	  //note: second rotation is below (common for LL and LR case)
	}
      else if  (val < subTree->right()->value())
	{
	  // recursively bring val to root of right-left
	  subTree->right()->left()=lookup( val, subTree->right()->left() );
	  
	  // if exists, do first step of LR (second is below)
	  if (subTree->right()->left())
	    subTree->right() = rotateWithLeftChild(subTree->right());
	}
      
      if (!subTree->right())
	return subTree;
      else
	return rotateWithRightChild(subTree);
    }
}

ostream&
SplayNode::print(ostream &os) const
{
  os << _val;//<< "(" << getHeight(_left) << "<->" << getHeight(_right) << ')';
  return os;
}

ostream& operator<<(ostream &os, const SplayNode &n)
{
  return n.print(os);
}
