//
// Created by Roy on 05/01/20.
//

#ifndef DATACENTERSMANAGER2_UNIONFIND_H
#define DATACENTERSMANAGER2_UNIONFIND_H

#include <iostream>

class UF_Node{
private:
    int head;
    int size;
public:
    UF_Node()= default;
    ~UF_Node()= default;
    int getHead() const {return head;}
    int getSize() const {return size;}
    void setHead(int given_head) { head = given_head ;}
    void setSize(int given_size) {size = given_size;}
};

class UnionFind{
private:
    UF_Node* groups_array;
public:
    explicit UnionFind(int size) {
        groups_array = new UF_Node[size];
        for(int i=1; i<=size; i++)	{
            groups_array[i].setHead(i);
            groups_array[i].setSize(1);
        }
    }
    ~UnionFind() {
        delete[] groups_array;
    }

    int find(int element)	{
        int head = element;
        while (head != groups_array[head].getHead())
            head = groups_array[head].getHead();
        while (element != head) {
            int temp_element = groups_array[element].getHead();
            groups_array[element].setHead(head);
            element = temp_element;
        }
        return head;
    }

    void unite(int e1, int e2)	{
        int e1_head = find(e1);
        int e2_head = find(e2);
        if (e1_head == e2_head) return;
        int new_size = groups_array[e1_head].getSize() + groups_array[e2_head].getSize();
        if (groups_array[e1_head].getSize() <= groups_array[e2_head].getSize()){
            groups_array[e1_head].setHead(e2_head);
            groups_array[e2_head].setSize(new_size);
        }
        else {
            groups_array[e2_head].setHead(e1_head);
            groups_array[e1_head].setSize(new_size);
        }
    }





};

#endif //DATACENTERSMANAGER2_UNIONFIND_H
