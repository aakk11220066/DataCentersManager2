//
// Created by Akiva on 2019-12-25.
//

#ifndef DATACENTERSMANAGER2_SET_H
#define DATACENTERSMANAGER2_SET_H

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
        SetNode(Set &container);
    };

    //find - returns set in which SetNode seeker is contained
    static Set &find(SetNode &seeker);

    //Union - unites sets into larger set (modifying larger set and
    // destroying smaller set)
    static Set &setsUnion(SetNode &node1, SetNode &node2);

    Set &setsUnion(const Set &otherSet);

    virtual bool operator==(const Set &rhs) const; //comparison by memory address

    //insert
    virtual void insert(SetNode &newComer);

private:
    unsigned int sizeNodes = 1;

    SetNode *root;

    //relation by size
    bool operator<(const Set &rhs) const;
};


//-----IMPLEMENTATIONS-------


bool Set::operator==(const Set &rhs) const {
    return this->root == rhs.root; //comparison by memory address of root
}

bool Set::operator<(const Set &rhs) const {
    return sizeNodes < rhs.sizeNodes;
}

void Set::insert(Set::SetNode &newComer) {
    if (!root) {
        root = &newComer;
        newComer.parent = nullptr;
        newComer.setContainer = this;
    } else {
        newComer.parent = root;
        newComer.setContainer = nullptr;
    }
    ++sizeNodes;
}

Set::SetNode *Set::SetNode::findRoot() {
    if (parent == nullptr) return this;
    return parent = parent->findRoot();
}

Set::SetNode::SetNode(Set &container) {
    container.insert(*this);
}

Set &Set::find(Set::SetNode &seeker) {
    return *(seeker.findRoot()->setContainer);
}

Set &Set::setsUnion(Set::SetNode &node1, Set::SetNode &node2) {
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

Set &Set::setsUnion(const Set &otherSet) {
    return setsUnion(*(this->root), *(otherSet.root));
}


#endif //DATACENTERSMANAGER2_SET_H