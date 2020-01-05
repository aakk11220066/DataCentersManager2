//
// Created by Akiva on 2019-12-25.
//

#ifndef DATACENTERSMANAGER2_SET_H
#define DATACENTERSMANAGER2_SET_H

template<class T>
class Set {
public:
    class SetNode {
        friend class Set;

    private: //DEBUGGING NOTE: make public to run test currently in main
        SetNode *parent = nullptr;
        Set *setContainer = nullptr; //only accurate for root

        //returns root of node, and updates parent to root
        SetNode *findRoot();

    public:
        //ctor
        SetNode(Set &container);

        //copy ctor
        SetNode(SetNode &original) = default;
    };

    //ctor
    Set(const T &data) : data(data) {}

    //operator=
    Set &operator=(const Set &original);

    //find - returns set in which SetNode seeker is contained
    static Set<T> &find(SetNode &seeker);

    //Union - unites sets into larger set (modifying larger set and
    // destroying smaller set)
    static Set &setsUnion(SetNode &node1, SetNode &node2);

    Set &setsUnion(const Set &otherSet);

    virtual bool operator==(const Set &rhs) const; //comparison by memory address

    //insert
    virtual SetNode &insert(SetNode &newComer);

private:
    unsigned int sizeNodes = 1;

    SetNode *root;

    T &data;
public:
    T &getData() const;

private:

    //relation by size
    bool operator<(const Set &rhs) const;
};


//-----IMPLEMENTATIONS-------

template<class T>
bool Set<T>::operator==(const Set<T> &rhs) const {
    return this->root == rhs.root; //comparison by memory address of root
}

template<class T>
bool Set<T>::operator<(const Set<T> &rhs) const {
    return sizeNodes < rhs.sizeNodes;
}

template<class T>
typename Set<T>::SetNode &Set<T>::insert(Set<T>::SetNode &newComer) {
    if (!root) {
        root = &newComer;
        newComer.parent = nullptr;
        newComer.setContainer = this;
    } else {
        newComer.parent = root;
        newComer.setContainer = nullptr;
    }
    ++sizeNodes;
    return newComer;
}

template<class T>
typename Set<T>::SetNode *Set<T>::SetNode::findRoot() {
    if (parent == nullptr) return this;
    return parent = parent->findRoot();
}

template<class T>
Set<T>::SetNode::SetNode(Set<T> &container) {
    container.insert(*this);
}

template<class T>
Set<T> &Set<T>::find(Set<T>::SetNode &seeker) {
    return *(seeker.findRoot()->setContainer);
}

template<class T>
Set<T> &Set<T>::setsUnion(Set<T>::SetNode &node1, Set<T>::SetNode &node2) {
    //get containing sets of nodes
    Set &set1 = find(node1);
    Set &set2 = find(node2);
    if (set1 == set2) return set1; //input sets are same set
    //sort sets by size
    Set &bigSet = (set1 < set2) ? set2 : set1;
    Set &smallSet = (set1 == bigSet) ? set2 : set1;
    //connect smaller set to larger, update sizes and disassociate child from set
    smallSet.root->setContainer = nullptr;
    smallSet.root->parent = bigSet.root;
    bigSet.sizeNodes += smallSet.sizeNodes;
    //destroy smaller set
    smallSet.sizeNodes = -999999999;
    smallSet.root = nullptr;
    smallSet.~Set();
    return bigSet;
}

template<class T>
Set<T> &Set<T>::setsUnion(const Set &otherSet) {
    return setsUnion(*(this->root), *(otherSet.root));
}

template<class T>
T &Set<T>::getData() const {
    return data;
}

template<class T>
Set<T> &Set<T>::operator=(const Set &original) {
    sizeNodes = original.sizeNodes;
    root = original.root;
    data = original.data;
    return *this;
}


#endif //DATACENTERSMANAGER2_SET_H