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


#endif //DATASTRUCTURESWETHW1_BINARYSEARCHTREE_H
