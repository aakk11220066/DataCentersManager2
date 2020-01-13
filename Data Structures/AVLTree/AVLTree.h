//
// Created by Akiva on 2019-11-29.
//

//upgraded to sum,rank capability

#ifndef DATACENTERSMANAGER_AVLTREE_H
#define DATACENTERSMANAGER_AVLTREE_H

#include "BinarySearchTree.h"
#include "../../DataManagerExceptions.h"

template <typename T>
class AVLTree : public BinarySearchTree<T>{
private:
    typedef typename BinaryTree<T>::BinaryTreeNode *
            BinTreeNodePtr;

    T &operatorSubscriptRecursive(typename BinaryTree<T>::BinaryTreeNode *root,
                                  unsigned int index);

    //node rotations
    static BinTreeNodePtr rotateRR(typename BinaryTree<T>::BinaryTreeNode &root);
    static BinTreeNodePtr rotateLL(typename BinaryTree<T>::BinaryTreeNode &root);
    static BinTreeNodePtr rotateRL(typename BinaryTree<T>::BinaryTreeNode &root);
    static BinTreeNodePtr rotateLR(typename BinaryTree<T>::BinaryTreeNode &root);

    //rebalance tree
    static BinTreeNodePtr fixBalance(typename BinaryTree<T>::BinaryTreeNode &root);

    //returns balance factor defined for standard AVL trees
    static int getBalanceFactor(typename BinaryTree<T>::BinaryTreeNode &node);

    //--- FRIENDS ---
    //for BinTreeNodePtr, BinaryTreeNode type usage
    template <typename U>
    friend unsigned int getRelativeIndexRecursive(
            typename BinaryTree<U>::BinaryTreeNode* root,
            const U& data);

    template<typename U>
    friend unsigned int height(typename AVLTree<U>::BinTreeNodePtr nodePtr);

    template<typename U>
    friend typename AVLTree<U>::BinTreeNodePtr
    insertRecursive(typename AVLTree<U>::BinTreeNodePtr rootPtr, const U &data);

    template<typename U>
    friend typename AVLTree<U>::BinTreeNodePtr
    getSuccessor(typename BinaryTree<U>::BinaryTreeNode &root);

    template<typename U>
    friend typename AVLTree<U>::BinTreeNodePtr
    destroy(typename AVLTree<U>::BinTreeNodePtr targetNode);

    template<typename U>
    friend typename AVLTree<U>::BinTreeNodePtr
    removeRecursive(typename AVLTree<U>::BinTreeNodePtr rootPtr, const U &data);

    template<typename U>
    friend void swapData(typename BinaryTree<U>::BinaryTreeNode &node1,
                         typename BinaryTree<U>::BinaryTreeNode &node2);

    template <typename U>
    friend int getPartialSumRecursive(const typename BinaryTree<U>::BinaryTreeNode* root,
                               const U& data);

public:
    //ctor
    AVLTree() = default;

    //dtor
    virtual ~AVLTree() = default;

    //copy ctor
    AVLTree(const AVLTree &original) = default;

    //operator=
    AVLTree &operator=(const AVLTree &original) = default;

    //conversion constructor from BinarySearchTree to AVLTree
    AVLTree(const BinarySearchTree<T> &original);

    //insert
    void insert(const T& data);

    /// \param data: element whose index you seek
    /// \return number of elements in tree lesser than data
    /// O(logn) time
    unsigned int getRelativeIndex(const T& data) const;

    /// \param index relative index of element to return
    /// \return //opposite of getRelativeIndex - returns the element with given
    /// index
    T &operator[](unsigned int index);

    /// \param data: element to sum tree up to
    /// \return sum of all elements in tree lesser than data (and data itself)
    /// O(logn) time
    int getPartialSum(const T& data) const;

    //remove
    void remove(const T& data);

    /// \return number of elements in tree
    int getTreeSize();
};


//-----------IMPLEMENTATIONS------------

template<typename T>
unsigned int height(typename AVLTree<T>::BinTreeNodePtr nodePtr) {
    return (nodePtr) ? nodePtr->getHeight() : 0;
}

template<typename T>
int AVLTree<T>::getBalanceFactor(typename BinaryTree<T>::BinaryTreeNode &node) {
    unsigned int heightLeft = height<T>(node.left);
    unsigned int heightRight = height<T>(node.right);
    return heightLeft - heightRight;
}

template<typename T>
typename AVLTree<T>::BinTreeNodePtr
AVLTree<T>::rotateRR(typename BinaryTree<T>::BinaryTreeNode &root) {

    //first update sum and subTreeSize, then perform rotation
    unsigned int originalRightSize = root.right->getSubtreeSize();
    int originalRightSum = root.right->getSum();
    //root.right gains root as a subtree, thus including root's entire left side
    root.right->sum += root.getSum() - root.right->getSum();
    root.right->subTreeSize += root.getSubtreeSize() - root.right->getSubtreeSize();
    //root now only has itself and its left subtree,
    // as well as root.right's left subtree
    root.sum -= (originalRightSum -
            ((root.right->left)? root.right->left->getSum() : 0));
    root.subTreeSize -= (originalRightSize -
            ((root.right->left)? root.right->left->getSubtreeSize() : 0));

    AVLTree<T>::BinTreeNodePtr temp = root.right->left;
    AVLTree<T>::BinTreeNodePtr output = root.right;
    root.right->left = &root;
    root.right = temp;
    return output;
}

template<typename T>
typename AVLTree<T>::BinTreeNodePtr
AVLTree<T>::rotateLL(typename BinaryTree<T>::BinaryTreeNode &root) {

    //first update sum and subTreeSize, then perform rotation
    unsigned int originalLeftSize = root.left->getSubtreeSize();
    int originalLeftSum = root.left->getSum();
    //root.right gains root as a subtree, thus including root's entire left side
    root.left->sum += root.getSum() - root.left->getSum();
    root.left->subTreeSize += root.getSubtreeSize() - root.left->getSubtreeSize();
    //root now only has itself and its left subtree,
    // as well as root.right's left subtree
    root.sum -= (originalLeftSum -
                 ((root.left->right)? root.left->right->getSum() : 0));
    root.subTreeSize -= (originalLeftSize -
                           ((root.left->right)? root.left->right->getSubtreeSize() : 0));

    AVLTree<T>::BinTreeNodePtr temp = root.left->right;
    AVLTree<T>::BinTreeNodePtr output = root.left;
    root.left->right = &root;
    root.left = temp;
    return output;
}

template<typename T>
typename AVLTree<T>::BinTreeNodePtr
AVLTree<T>::rotateRL(typename BinaryTree<T>::BinaryTreeNode &root) {

    root.right = rotateLL(*(root.right));
    return rotateRR(root);
}

template<typename T>
typename AVLTree<T>::BinTreeNodePtr
AVLTree<T>::rotateLR(typename BinaryTree<T>::BinaryTreeNode &root) {

    root.left = rotateRR(*(root.left));
    return rotateLL(root);
}

template<typename T>
typename AVLTree<T>::BinTreeNodePtr
AVLTree<T>::fixBalance(typename BinaryTree<T>::BinaryTreeNode &root) {

    AVLTree<T>::BinTreeNodePtr output;

    int balanceFactor = getBalanceFactor(root);
    if (abs(balanceFactor) != 2) output = &root;
    else if (balanceFactor == 2 && getBalanceFactor(*(root.left)) == -1) {
        output = rotateLR(root);
    } else if (balanceFactor == 2) {
        output = rotateLL(root);
    } else if (getBalanceFactor(*(root.right)) == 1) output = rotateRL(root);
    else output = rotateRR(root);

    root.getHeight(); //update height
    return output;
}

template<typename T>
typename AVLTree<T>::BinTreeNodePtr
insertRecursive(typename AVLTree<T>::BinTreeNodePtr rootPtr, const T &data) {

    int numericalValue = (data+data)/2; //for sum.  Must use + to calculate!
    if (!rootPtr) { //reached position for new element
        auto output = new typename BinaryTree<T>::BinaryTreeNode(data);
        output->sum = numericalValue;
        return output;
    }
    if (rootPtr->data == data) {
        throw DataManagerExceptions::ObjectAlreadyExists();
    }

    if (data > rootPtr->data) { //go right
        rootPtr->right = insertRecursive(rootPtr->right, data);
        rootPtr->sum += numericalValue; //if succeeded, add value to sum
        ++(rootPtr->subTreeSize); //increment size of subtree
        return AVLTree<T>::fixBalance(*rootPtr);
    }
    rootPtr->left = insertRecursive(rootPtr->left, data); //go left
    rootPtr->sum += numericalValue;
    ++(rootPtr->subTreeSize);
    return AVLTree<T>::fixBalance(*rootPtr);
}

template<typename T>
void AVLTree<T>::insert(const T &data) {
    this->root = insertRecursive(this->root, data);
}

template<typename T>
void swapData(typename BinaryTree<T>::BinaryTreeNode &node1,
              typename BinaryTree<T>::BinaryTreeNode &node2) {

    T temp = node1.data;
    node1.data = node2.data;
    node2.data = temp;
}

//finds the next greatest element to root in root's subtree
//assumes root has a right child
template<typename T>
typename AVLTree<T>::BinTreeNodePtr
getSuccessor(typename BinaryTree<T>::BinaryTreeNode &root) {

    typename AVLTree<T>::BinTreeNodePtr successor = root.right;
    while (successor->left) {
        successor = successor->left;
    }

    return successor;
}

template<typename T>
typename AVLTree<T>::BinTreeNodePtr
destroy(typename AVLTree<T>::BinTreeNodePtr targetNode) {

    //targetNode has no children - return empty subtree
    if (!(targetNode->right) && !(targetNode->left)) {
        return targetNode->deleteSingleNode();
    }

    //targetNode has only left child
    if (!(targetNode->right)) {
        return targetNode->deleteSingleNode();
    }

    //targetNode has only right child
    if (!(targetNode->left)) {
        return targetNode->deleteSingleNode();
    }

    //targetNode has 2 children
    /*swap data between targetNode and next greatest node, then remove next
     * greatest node from subtree from whence it came
     * (greater => right subtree).
     * Successor will have only 1 child maximum, by property of BST
     */
    typename AVLTree<T>::BinTreeNodePtr successorNode = getSuccessor<T>(*targetNode);
    swapData<T>(*targetNode, *successorNode);
    targetNode->right = removeRecursive(targetNode->right, successorNode->data);
    return AVLTree<T>::fixBalance(*targetNode);
}

template<typename T>
typename AVLTree<T>::BinTreeNodePtr
removeRecursive(typename AVLTree<T>::BinTreeNodePtr rootPtr, const T &data) {

    if (!rootPtr) throw DataManagerExceptions::ObjectUnfound();
    else if (data == rootPtr->data) {
        return destroy<T>(rootPtr);
    } else if (data > rootPtr->data) {
        rootPtr->right = removeRecursive(rootPtr->right, data);
    } else {
        rootPtr->left = removeRecursive(rootPtr->left, data);
    }
    return AVLTree<T>::fixBalance(*rootPtr);
}

template<typename T>
void AVLTree<T>::remove(const T &data) {
    this->root = removeRecursive(this->root, data);
}

template <typename T>
unsigned int getRelativeIndexRecursive(
        typename BinaryTree<T>::BinaryTreeNode* root,
        const T& data){

    unsigned int rightSize = (root->right)? root->right->getSubtreeSize() : 0;
    unsigned int leftAndRootSize  = root->getSubtreeSize() - rightSize;
    if (data == root->data) return leftAndRootSize - 1;
    if (data > root->data) {
        return getRelativeIndexRecursive(root->right, data) + leftAndRootSize;
    }
    else return getRelativeIndexRecursive(root->left, data);
}

template<typename T>
unsigned int AVLTree<T>::getRelativeIndex(const T &data) const {
    this->find(data); //ensure data is actually in tree
    return getRelativeIndexRecursive(this->root, data);
}

template <typename T>
int getPartialSumRecursive(const typename BinaryTree<T>::BinaryTreeNode* root,
        const T& data) {
    unsigned int rightSum = (root->right)? root->right->getSum() : 0;
    unsigned int leftAndRootSum  = root->getSum() - rightSum;
    if (data == root->data) return leftAndRootSum;
    if (data > root->data) {
        return getPartialSumRecursive(root->right, data) + leftAndRootSum;
    }
    else return getPartialSumRecursive(root->left, data);
}

template<typename T>
int AVLTree<T>::getPartialSum(const T &data) const {
    this->find (data); //ensure data is actually in tree
    return getPartialSumRecursive(this->root, data);
}

template<typename T>
AVLTree<T>::AVLTree(const BinarySearchTree<T> &original):BinarySearchTree<T>(original) {}

template<typename T>
T &AVLTree<T>::operator[](unsigned int index) {
    return operatorSubscriptRecursive(this->root, index);
}

template<typename T>
T &AVLTree<T>::operatorSubscriptRecursive(
        typename BinaryTree<T>::BinaryTreeNode *root, unsigned int index) {

    if (!root) throw DataManagerExceptions::ObjectUnfound();

    unsigned int rootIndex = getRelativeIndex(root->data);
    if (rootIndex == index) return root->data;
    if (rootIndex > index) return operatorSubscriptRecursive(root->left, index);
    return operatorSubscriptRecursive(root->right, index);
}

template<typename T>
int AVLTree<T>::getTreeSize() {
    return this->getSize();
}


#endif //DATACENTERSMANAGER_AVLTREE_H
