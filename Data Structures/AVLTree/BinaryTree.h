//
//
// Created by Akiva on 2019-11-28.
//

#ifndef DATASTRUCTURESWETHW1_BINARYTREE_H
#define DATASTRUCTURESWETHW1_BINARYTREE_H

#include "../Array.h"
#include <memory>
#include <algorithm> //for function max
#include <math.h>
#include <cassert>

template<typename T>
class BinaryTree {

protected:
    class BinaryTreeNode {
    private:
        unsigned int height = 1;
    public:
        unsigned int subTreeSize=1; //size of subtree.  AVLTree only
        int sum = 0; //sum = sum of subtree.  AVLTree only //TODO: should this really be int?
        T data;
        BinaryTreeNode *left = nullptr, *right = nullptr;

        //ctor
        explicit BinaryTreeNode(const T &data);

        //dtor
        virtual ~BinaryTreeNode();

        //Deletes a single node, returning its child.  Assumes node has single child
        BinaryTreeNode *deleteSingleNode();

        //copy ctor
        BinaryTreeNode(const BinaryTreeNode &original);

        //operator=
        BinaryTreeNode &operator=(const BinaryTreeNode &original);

        //receives output array and heap-allocated index, returns inOrder of sub-tree
        Array<T> &getInOrderRecursive(Array<T> &output, unsigned int &indexOffset) const;

        //receives output array and heap-allocated index, returns inOrder of
        // pointers to nodes of sub-tree
        Array<BinaryTreeNode *> &getNodesInOrderRecursive(
                Array<BinaryTreeNode *> &output, unsigned int &indexOffset);

        //returns height of node after modification of tree
        int getHeight();

        //comparison based on data comparators
        bool operator>(const BinaryTreeNode &other);

        //AVL TREE ONLY
        //returns rank (size of subtree) of node
        unsigned int getSubtreeSize() const;

        //AVL TREE ONLY
        //returns sum of subtree of node
        unsigned int getSum() const;
    };

    typedef void nodeAction(BinaryTreeNode& target);

    static BinaryTree<T> almostCompleteTree(unsigned int size);

    //AVL TREE ONLY
    unsigned int getSize() const;

    //fix attributes of entire tree
    //O(n)
    virtual void updateHeight();

    virtual void updateSum();

    virtual void updateSubTreeSize();

private:
    //helper recursive functions
    virtual void updateHeightRecursive(BinaryTreeNode *root);

    virtual int updateSumRecursive(BinaryTreeNode *root);

    virtual unsigned int updateSubTreeSizeRecursive(BinaryTreeNode *root);

protected:
    BinaryTreeNode *root = nullptr;

    //get Array of nodes inorder
    Array<BinaryTreeNode *> getNodesInOrder() const;

private:
    unsigned int getSize(const BinaryTreeNode *root) const;

    static BinaryTreeNode *almostCompleteTreeRecursive(BinaryTreeNode *root, unsigned int size);

public:
    //ctor
    BinaryTree() = default;

    //dtor
    virtual ~BinaryTree();

    //copy ctor
    BinaryTree(const BinaryTree &original);

    //operator=
    BinaryTree &operator=(const BinaryTree &original);

    //get array of tree, ordered inOrder
    Array<T> getInOrder() const;
};



//-----------IMPLEMENTATIONS------------

template<typename T>
Array<T> BinaryTree<T>::getInOrder() const { //wrapper for recursive call
    const auto constThis = const_cast<BinaryTree *> (this);
    Array<T> output = Array<T>(constThis->getSize(root));
    if (!root) return output;

    //remember placement in output array
    unsigned int *indexOffset = new unsigned int;
    *indexOffset = 0; //start at beginning

    root->getInOrderRecursive(output, *indexOffset);

    delete indexOffset;
    return output;
}

template<typename T>
Array<T> &BinaryTree<T>::BinaryTreeNode::getInOrderRecursive(Array<T> &output, unsigned int &indexOffset) const {

    if (this->left) {
        this->left->getInOrderRecursive(output, indexOffset);
    }

    output[indexOffset] = this->data;
    ++(indexOffset);

    if (this->right) {
        this->right->getInOrderRecursive(output, indexOffset);
    }

    return output;
}

template<typename T>
//runtime: O(n)
unsigned int BinaryTree<T>::getSize(const
                                    BinaryTree::BinaryTreeNode *root) const {

    if (!root) return 0;
    return 1 +
           ((root->left) ? getSize(root->left) : 0) +
           ((root->right) ? getSize(root->right) : 0);
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
    delete (root);
}

template<typename T>
unsigned int BinaryTree<T>::getSize() const {
    return getSize(root);
}

template<typename T>
Array<typename BinaryTree<T>::BinaryTreeNode *> BinaryTree<T>::getNodesInOrder() const {
    Array<BinaryTreeNode *> output = Array<BinaryTreeNode *>(this->getSize(root));
    if (!root) return output;

    //remember placement in output array
    unsigned int *indexOffset = new unsigned int;
    *indexOffset = 0; //start at beginning

    root->getNodesInOrderRecursive(output, *indexOffset);

    delete indexOffset;
    return output;
}

template<typename T>
BinaryTree<T> BinaryTree<T>::almostCompleteTree(unsigned int size) {
    BinaryTree<T> output = BinaryTree<T>();
    output.root = almostCompleteTreeRecursive(output.root, size);

    return output;
}

template<typename T>
typename BinaryTree<T>::BinaryTreeNode *
BinaryTree<T>::almostCompleteTreeRecursive(BinaryTree::BinaryTreeNode *root,
                                           unsigned int size) {

    assert (!root);
    if (size == 0) return nullptr;
    root = new typename BinaryTree<T>::BinaryTreeNode(T());
    if (size == 1) return root;

    //size = n
    //depth = h = ceiling(log(n+1)) - 1
    //bottom row size = BRS = 2^h - ((2^(h+1)-1) - n) = n + 1 - 2^h
    //internal nodes = n-1-BRS
    //left bottom row = (BRS >= 2^(h-1))? 2^(h-1) : BRS
    //right bottom row = (BRS >= 2^(h-1))? BRS-2^(h-1) : 0
    unsigned int depth = ceil(log2(size + 1)) - 1;
    unsigned int bottomRowSize = size + 1 - pow(2, depth);
    unsigned int leftBottomRow =
            (bottomRowSize >= pow(2, (depth - 1))) ? pow(2, depth - 1) : bottomRowSize;
    unsigned int rightBottomRow =
            (bottomRowSize >= pow(2, (depth - 1))) ? bottomRowSize - pow(2, depth - 1) : 0;
    unsigned int numInternalNodes = size - 1 - bottomRowSize;
    unsigned int leftTreeSize = numInternalNodes / 2 + leftBottomRow;
    unsigned int rightTreeSize = numInternalNodes / 2 + rightBottomRow;

    root->left = almostCompleteTreeRecursive(root->left, leftTreeSize);
    root->right = almostCompleteTreeRecursive(root->right, rightTreeSize);
    root->getHeight();
    return root;
}

template<typename T>
Array<typename BinaryTree<T>::BinaryTreeNode *> &BinaryTree<T>::BinaryTreeNode::getNodesInOrderRecursive(
        Array<BinaryTree::BinaryTreeNode *> &output, unsigned int &indexOffset) {

    if (this->left) {
        this->left->getNodesInOrderRecursive(output, indexOffset);
    }

    output[indexOffset] = this;
    ++(indexOffset);

    if (this->right) {
        this->right->getNodesInOrderRecursive(output, indexOffset);
    }

    return output;
}

template<typename T>
typename BinaryTree<T>::BinaryTreeNode *
BinaryTree<T>::BinaryTreeNode::deleteSingleNode() {

    BinaryTreeNode *child = (this->right) ? this->right : this->left;
    right = left = nullptr;
    delete (this);
    return child;
};

template<typename T>
BinaryTree<T>::BinaryTreeNode::BinaryTreeNode(const T &data) : data(data) {}

template<typename T>
BinaryTree<T>::BinaryTreeNode::~BinaryTreeNode() {
    delete (left);
    delete (right);
}

template<typename T>
int BinaryTree<T>::BinaryTreeNode::getHeight() {
    unsigned int leftHeight = (left) ? left->height : 0;
    unsigned int rightHeight = (right) ? right->height : 0;
    return height = 1 + std::max(leftHeight, rightHeight);
}


template<typename T>
unsigned int BinaryTree<T>::BinaryTreeNode::getSubtreeSize() const {
    return subTreeSize;
}

template<typename T>
unsigned int BinaryTree<T>::BinaryTreeNode::getSum() const {
    return sum;
}

template<typename T>
bool BinaryTree<T>::BinaryTreeNode::operator>(const BinaryTree::BinaryTreeNode &other) {
    return data > other.data;
}

template<typename T>
BinaryTree<T>::BinaryTreeNode::BinaryTreeNode(const BinaryTree::BinaryTreeNode &original) :
        height(original.height), subTreeSize(original.subTreeSize),
        sum(original.sum), data(original.data) {

    left = (original.left) ? new BinaryTreeNode(*(original.left)) : nullptr;
    right = (original.right) ? new BinaryTreeNode(*(original.right)) : nullptr;
}

template<typename T>
typename BinaryTree<T>::BinaryTreeNode &BinaryTree<T>::BinaryTreeNode::operator=(
        const BinaryTree::BinaryTreeNode &original) {

    delete (left);
    delete (right);

    height = original.height;
    subTreeSize = original.subTreeSize;
    sum = original.sum;
    data = original.data;
    left = (original.left) ? BinaryTreeNode(original.left) : nullptr;
    right = (original.right) ? BinaryTreeNode(original.right) : nullptr;
    return *this;
}

template<typename T>
void BinaryTree<T>::updateHeight() {
    updateHeightRecursive(this->root);
}

template<typename T>
void BinaryTree<T>::updateSum() {
    updateSumRecursive(this->root);
}

template<typename T>
void BinaryTree<T>::updateSubTreeSize() {
    updateSubTreeSizeRecursive(this->root);
}

template<typename T>
void BinaryTree<T>::updateHeightRecursive(typename BinaryTree::BinaryTreeNode *root) {
    //postorder
    if (!root) return;
    updateHeightRecursive(root->left);
    updateHeightRecursive(root->right);
    root->getHeight();
}
/*
template<typename T>
int BinaryTree<T>::updateSumRecursive(typename BinaryTree::BinaryTreeNode *root) {
    //postorder
    if (!root) return 0;

    return root->sum = (root->data + root->data) / 2 +
                       updateSumRecursive(root->left) +
                       updateSumRecursive(root->right);
}

template<typename T>
unsigned int BinaryTree<T>::updateSubTreeSizeRecursive(typename BinaryTree::BinaryTreeNode *root) {
    //postorder
    if (!root) return 0;

    return root->subTreeSize = 1 +
                               updateSubTreeSizeRecursive(root->left) +
                               updateSubTreeSizeRecursive(root->right);
}
*/
template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree &original) :
        root(new BinaryTreeNode(*(original.root))) {}

template<typename T>
BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree &original) {
    delete (root);
    root = (original.root) ? new BinaryTreeNode(*(original.root)) : nullptr;
    return *this;
}

#endif //DATASTRUCTURESWETHW1_BINARYTREE_H
