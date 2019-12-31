//
// Created by Akiva on 2019-11-28.
//

#ifndef DATASTRUCTURESWETHW1_BINARYSEARCHTREE_H
#define DATASTRUCTURESWETHW1_BINARYSEARCHTREE_H

#include "BinaryTree.h"

template<typename T>
class BinarySearchTree : public BinaryTree<T> {
private:
    static void doNothing(typename BinaryTree<T>::BinaryTreeNode& target);

    typename BinaryTree<T>::BinaryTreeNode *getInOrderCopyRecursive(
            typename BinaryTree<T>::BinaryTreeNode *root,
            Array<typename BinaryTree<T>::BinaryTreeNode *> source,
            unsigned int *index);

    //replaces nodes of tree inorder with nodes pointed to by source
    BinarySearchTree<T> &inOrderCopy(const Array<typename BinaryTree<T>::BinaryTreeNode *> &source);

    explicit BinarySearchTree(const BinaryTree<T> &original);

    //----FRIENDS----
    //to grant access to BinaryTreeNode from superclass
    template<typename U>
    friend typename BinaryTree<U>::BinaryTreeNode* findRecursive(
            typename BinaryTree<U>::BinaryTreeNode *root, const U &data,
            typename BinaryTree<U>::nodeAction action);

protected:
    typename BinaryTree<T>::BinaryTreeNode* findNodeOf(const T& data,
            typename BinaryTree<T>::nodeAction action=doNothing) const;

public:
    //ctor
    explicit BinarySearchTree() = default;

    //dtor
    virtual ~BinarySearchTree() = default;

    //copy ctor
    BinarySearchTree(const BinarySearchTree &original) = default;

    //operator=
    BinarySearchTree &operator=(const BinarySearchTree &original) = default;

    //find
    virtual T &find(const T &data) const;

    //AVL TREE ONLY
    //merge - merges 2 trees into a single almost-complete binary search tree
    virtual BinarySearchTree merge(const BinarySearchTree &tree);
};



//-----------IMPLEMENTATIONS------------

#include "../../DataManagerExceptions.h"

//recursively find node containing data and apply action to every node en route
template<typename T>
typename BinaryTree<T>::BinaryTreeNode* findRecursive(
        typename BinaryTree<T>::BinaryTreeNode *root,
        const T &data,
        typename BinaryTree<T>::nodeAction action) {

    if (!root) return nullptr;
    action(*root); //perform action on root node
    if (data == root->data) return root;
    if (data > root->data) return findRecursive(root->right, data, action);
    else return findRecursive(root->left, data, action);
}

template<typename T>
T &BinarySearchTree<T>::find(const T &data) const {
    typename BinaryTree<T>::BinaryTreeNode* output = findNodeOf(data);
    if (!output) throw DataManagerExceptions::ObjectUnfound();
    else return output->data;
}

//find node containing data and apply action to every node en route,
// starting at root
template<typename T>
typename BinaryTree<T>::BinaryTreeNode *BinarySearchTree<T>::findNodeOf(
        const T &data,
        typename BinaryTree<T>::nodeAction action) const {

    return findRecursive(this->root, data, action);
}

template<typename T>
void BinarySearchTree<T>::doNothing(typename BinaryTree<T>::BinaryTreeNode &target) {}

template<typename T>
BinarySearchTree<T> BinarySearchTree<T>::merge(const BinarySearchTree &tree) {
    Array<typename BinaryTree<T>::BinaryTreeNode *> myNodes = this->getNodesInOrder();
    Array<typename BinaryTree<T>::BinaryTreeNode *> hisNodes = tree.getNodesInOrder();
    //inorder list of all elements in both trees
    Array<typename BinaryTree<T>::BinaryTreeNode *> allElements = myNodes.merge(hisNodes);

    BinarySearchTree<T> output = BinaryTree<T>::almostCompleteTree(allElements.getSize());
    output.inOrderCopy(allElements);

    return output;
}

template<typename T>
BinarySearchTree<T> &BinarySearchTree<T>::inOrderCopy(const Array<typename BinaryTree<T>::BinaryTreeNode *> &source) {
    //unsigned int sourceSize = source.getSize();
    //unsigned int thisSize = this->getSize();
    //if (thisSize != sourceSize) throw DataManagerExceptions::IllegalSize();

    unsigned int *index = new unsigned int;
    *index = 0;
    this->root = getInOrderCopyRecursive(this->root, source, index);
    delete index;

    this->updateHeight();
    this->updateSum();
    this->updateSubTreeSize();
    return *this;
}

template<typename T>
typename BinaryTree<T>::BinaryTreeNode *BinarySearchTree<T>::getInOrderCopyRecursive(
        typename BinaryTree<T>::BinaryTreeNode *root,
        Array<typename BinaryTree<T>::BinaryTreeNode *> source,
        unsigned int *index) {

    if (!root) return nullptr;

    //handle left subtree
    if (root->left) {
        root->left = getInOrderCopyRecursive(root->left, source, index);
    }

    //handle root
    unsigned int iterationIndex = *index;
    /* replace root with source
    source[iterationIndex] -> left = root->left;
    source[iterationIndex] -> right = root->right;
    */
    //copy source into root
    root->data = source[iterationIndex]->data;

    ++(*index);

    //handle right subtree
    if (root->right) {
        root->right = getInOrderCopyRecursive(root->right, source,
                                              index); //source[iterationIndex] instead of root at first for replacement
    }

    return root; //source[iterationIndex] instead of root for replacement
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinaryTree<T> &original):BinaryTree<T>(original) {}


#endif //DATASTRUCTURESWETHW1_BINARYSEARCHTREE_H
