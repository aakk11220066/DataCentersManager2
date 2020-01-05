//
// Created by Akiva on 2020-01-05.
//

#ifndef DATACENTERSMANAGER2_UNIONFIND_H
#define DATACENTERSMANAGER2_UNIONFIND_H

#include "Set.h"
#include "../Data Structures/Array.h"

//Roi: let me know if you would like this to be generic (template)
class UnionFind {
private:
    Array<Set<int>> sets;

    unsigned int nextAdditionIndex = 0; //index in sets Array to add next set into

public:
    //ctor
    UnionFind(unsigned int maxSets) : sets(maxSets) {}

    //dtor
    virtual ~UnionFind() = default;

    //copy ctor
    UnionFind(const UnionFind &original) = default;

    //operator=
    UnionFind &operator=(const UnionFind &original) = default;

    //addSet
    Set<int> &addSet(int data);

    /// \param set: set to add new element to
    /// \return SetNode for access to the UnionFind system
    Set<int>::SetNode addElement(Set<int> &set);

    //union
    Set<int> &setUnion(Set<int> &set1, Set<int> &set2);

    Set<int> &setUnion(Set<int>::SetNode node1, Set<int>::SetNode node2);

    //getSetData
    int getSetData(Set<int>::SetNode &element);
};

Set<int> &UnionFind::addSet(int data) {
    return sets[nextAdditionIndex++] = Set<int>(data);
}

Set<int>::SetNode UnionFind::addElement(Set<int> &set) {
    Set<int>::SetNode node = Set<int>::SetNode(set);
    return set.insert(node);
}

Set<int> &UnionFind::setUnion(Set<int> &set1, Set<int> &set2) {
    return set1.setsUnion(set2);
}

Set<int> &UnionFind::setUnion(Set<int>::SetNode node1, Set<int>::SetNode node2) {
    return Set<int>::find(node1).setsUnion(Set<int>::find(node2));
}

int UnionFind::getSetData(Set<int>::SetNode &element) {
    return Set<int>::find(element).getData();
}

#endif //DATACENTERSMANAGER2_UNIONFIND_H
