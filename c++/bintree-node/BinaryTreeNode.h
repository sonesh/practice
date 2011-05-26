#ifndef BINARY_TREE_NODE_H_INCLUDED
#define BINARY_TREE_NODE_H_INCLUDED

#include <cstdlib>   //provides NULL and std::size_t
#include <iostream>  //provides std::cout
#include <iomanip>   //provides std::setw

template <class Item>
class BinaryTreeNode {

 public:
  //Typedefs
  typedef Item value_type;

  //Constructors
  BinaryTreeNode (const Item& initData  = Item (),
                  BinaryTreeNode *left  = NULL, 
                  BinaryTreeNode *right = NULL) {
    data_  = initData;
    left_  = left;
    right_ = right;
  }

  //Constant member functions
  const Item& getData () const {return data_;}
  const BinaryTreeNode* getLeft  () const { return left_; }
  const BinaryTreeNode* getRight () const { return right_; }
  bool isLeaf() const { return ((left_ == NULL) && (right_ == NULL)); }
  
  //Modification member functions
  Item& getData() { return data_; }
  BinaryTreeNode* getLeft  ()  { return left_; }
  BinaryTreeNode* getRight () { return right_; }
  void setData  (const Item& data) { data_ = data; }
  void setLeft  (BinaryTreeNode* left) { left_ = left; }
  void setRight (BinaryTreeNode* right) { right_ = right; }

 private:
  Item data_;
  BinaryTreeNode *left_;
  BinaryTreeNode *right_;

};

//Non member functions
template <class Item>
void treeClear (BinaryTreeNode<Item>*& rootPtr);

template <class Item>
BinaryTreeNode<Item>* treeCopy (const BinaryTreeNode<Item>* rootPtr);

template <class Item>
std::size_t treeSize (const BinaryTreeNode<Item>* rootPtr);

template <class Item, class SizeType>
void prettyPrint (const BinaryTreeNode<Item>* rootPtr, SizeType depth);

#include "BinaryTreeNode.template"

#endif
