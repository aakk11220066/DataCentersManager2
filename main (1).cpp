
#include <iostream>
#include <assert.h>
//#include "RankAVL.h"
#include "library2.h"
//#include "unionFind.h"
#include "DataCenterManager.h"
//#include "generic_linkedList.h"
//#include "hashtable.h"

using namespace std;

int main() {
/*
//RANK_AVLTREE_TESTS:

    RankAVLtree<int>* rt_1 = new RankAVLtree<int>();
    RankAVLtree<int>* rt_2 = new RankAVLtree<int>();
    RankAVLtree<int>* rt_3 = new RankAVLtree<int>();
    for(int i=0; i<10; ++i)
        rt_1->AVLtreeInsertNode(i, i, NULL, rt_1->AVLtreeGetRoot());
    for(int i=0; i<10; ++i)
        rt_2->AVLtreeInsertNode(i+10, i+10, NULL, rt_2->AVLtreeGetRoot());
    rt_3 = rt_3->AVLtreeMergeTwoTrees(rt_1, rt_2, rt_3);
    rt_3->AVLtreeRemoveNodeByKey(9, 9, rt_3->AVLtreeGetRoot(), true);//remove root
    rt_3->AVLtreeRemoveNodeByKey(6, 6, rt_3->AVLtreeGetRoot(), true);//remove node with 2 children
    rt_3->AVLtreeRemoveNodeByKey(7, 7, rt_3->AVLtreeGetRoot(), true);//remove node with right son only
    rt_3->AVLtreeRemoveNodeByKey(10, 10, rt_3->AVLtreeGetRoot(), true);//remove left leaf
    rt_3->AVLtreeRemoveNodeByKey(19, 19, rt_3->AVLtreeGetRoot(), true);//remove right leaf
    rt_3->AVLtreeRemoveNodeByKey(1, 1, rt_3->AVLtreeGetRoot(), true);//remove node with left son only
    // check rt_3 (all ranks) has been successfully updated!!!
    delete rt_3;

// UF_TESTS:

    unionFind<int>* uf_1 = new unionFind<int>(10);
    for (int i=1; i<=10; ++i){
        assert(uf_1->unionFindFind(i)->getKey()==i);
    }
    assert(*uf_1->unionFindUnionAndGetRootData(1,2)==1);
    assert(*uf_1->unionFindUnionAndGetRootData(3,4)==3);
    assert(*uf_1->unionFindUnionAndGetRootData(2,4)==1);
    assert(uf_1->unionFindFind(4)->getKey()==1); //check route has been successfully shrinked!!!
    assert(uf_1->unionFindFind(3)->getKey()==1); //check route has been successfully shrinked!!!
    assert(*uf_1->unionFindUnionAndGetRootData(5,6)==5);
    assert(*uf_1->unionFindUnionAndGetRootData(6,5)==5);
    assert(*uf_1->unionFindUnionAndGetRootData(7,8)==7);
    assert(*uf_1->unionFindUnionAndGetRootData(9,8)==7);
    assert(*uf_1->unionFindUnionAndGetRootData(5,9)==7);
    assert(*uf_1->unionFindUnionAndGetRootData(2,8)==7);

    delete uf_1;

    unionFind<int>* uf_2 = new unionFind<int>(10);
    for (int i=1; i<=10; ++i){
        assert(uf_2->unionFindFind(i)->getKey()==i);
    }
    assert(*uf_2->unionFindUnionAndGetRootData(2,2)==2);
    assert(*uf_2->unionFindUnionAndGetRootData(3,4)==3);
    assert(*uf_2->unionFindUnionAndGetRootData(1,4)==3);
    assert(uf_2->unionFindFind(1)->getKey()==3); //check route has been successfully shrinked!!!
    assert(*uf_2->unionFindUnionAndGetRootData(5,1)==3);
    assert(*uf_2->unionFindUnionAndGetRootData(6,1)==3);
    assert(*uf_2->unionFindUnionAndGetRootData(7,6)==3);
    assert(*uf_2->unionFindUnionAndGetRootData(9,8)==9);
    assert(*uf_2->unionFindUnionAndGetRootData(10,4)==3);
    assert(uf_2->unionFindFind(8)->getKey()==9);
    assert(uf_2->unionFindFind(5)->getKey()==3);
    assert(uf_2->unionFindFind(10)->getKey()==3);

    delete uf_2;

// GENERIC_LINKEDLIST_TESTS:

    linkedList<int>* gls = new linkedList<int>();
    int* h = new int(1);
    int* i = new int(2);
    int* j = new int(3);
    int* k = new int(4);
    int* l = new int(5);
    gls->listAdd(h);
    gls->listAdd(i);
    gls->listAdd(j);
    gls->listAdd(k);
    gls->listAdd(l);
    gls->listRemoveByData(h);//remove first node
    gls->listRemoveByData(j);//remove mid node
    gls->listRemoveByData(l);//remove last node
    //check gls (size+nodes) has been successfully updated!!!
    gls->listRemoveByData(i);
    gls->listRemoveByData(k);
    int* m = new int(6);
    int* n = new int(7);
    gls->listAdd(m);//add first node
    gls->listAdd(n);//add last node
    //check gls (size+nodes) has been successfully updated!!!
    delete gls;


//HASH_TABLE_TESTS:

    hashTable<int>* ht = new hashTable<int>();
    int* aa = new int(1);
    int* bb = new int(2);
    int* cc = new int(3);
    int* dd = new int(4);
    int* ee = new int(5);
    int* ff = new int(6);
    int* gg = new int(7);
    int* hh = new int(8);
    int* ii = new int(9);
    int* jj = new int(10);
    int* kk = new int(11);
    int* ll = new int(12);
    ht->hashTableInsert(*aa, aa);
    ht->hashTableInsert(*bb, bb);
    ht->hashTableInsert(*cc, cc);
    ht->hashTableInsert(*dd, dd);
    assert(ht->hashTableGetTableSize()==4);
    ht->hashTableInsert(*ee, ee);
    ht->hashTableInsert(*ff, ff);
    ht->hashTableInsert(*gg, gg);
    ht->hashTableInsert(*hh, hh);
    assert(ht->hashTableGetTableSize()==8);
    ht->hashTableInsert(*ii, ii);
    ht->hashTableInsert(*jj, jj);
    ht->hashTableInsert(*kk, kk);
    ht->hashTableInsert(*ll, ll);
    //check hash table has been successfully updated!!!
    for(int i=1; i<=12; ++i){
        assert(ht->hashTableFind(i) == HASHTABLE_SUCCESS);
    }
    for(int i=1; i<=5; ++i){
        ht->hashTableRemove(i);
    }
    assert(ht->hashTableGetTableSize()==4);
    //check hash table has been successfully updated!!!
    for(int i=1; i<=5; ++i){
        assert(ht->hashTableFind(i) == HASHTABLE_FAILURE);
    }
    for(int i=6; i<=12; ++i){
        assert(ht->hashTableFind(i) == HASHTABLE_SUCCESS);
    }

    delete ht;
*/
//MANAGER_TESTS:

    void **DS = new (void *);
    *DS = Init(4);
    assert(*DS != NULL);
    StatusType s = AddServer(*DS, 5, 5);
    assert(s == INVALID_INPUT);
    s = AddServer(*DS, 0, 5);
    assert(s == INVALID_INPUT);
    s = AddServer(*DS, -1, 5);
    assert(s == INVALID_INPUT);
    s = AddServer(*DS, 5, 0);
    assert(s == INVALID_INPUT);
    s = AddServer(*DS, 5, -1);
    assert(s == INVALID_INPUT);
    s = AddServer(nullptr, 5, -44);
    assert(s == INVALID_INPUT);
    s = AddServer(*DS, 1, 1);
    assert(s == SUCCESS);
    s = AddServer(*DS, 2, 1);
    assert(s == FAILURE);
    s = AddServer(*DS, 2, 2);
    assert(s == SUCCESS);
    s = AddServer(*DS, 2, 3);
    assert(s == SUCCESS);
    s = AddServer(*DS, 2, 4);
    assert(s == SUCCESS);
    s = AddServer(*DS, 2, 5);
    assert(s == SUCCESS);
    s = AddServer(*DS, 3, 5);
    assert(s == FAILURE);
    s = AddServer(*DS, 3, 6);
    assert(s == SUCCESS);
    s = AddServer(*DS, 3, 7);
    assert(s == SUCCESS);
    s = AddServer(*DS, 4, 8);
    assert(s == SUCCESS);
    s = AddServer(*DS, 4, 9);
    assert(s == SUCCESS);
    s = AddServer(*DS, 4, 10);
    assert(s == SUCCESS);//check hash table has been successfully updated!!!
    int sum = 0;
    s = SumHighestTrafficServers(*DS, 1, -1, &sum);
    assert(s == INVALID_INPUT);
    s = SumHighestTrafficServers(*DS, 5, 1, &sum);
    assert(s == INVALID_INPUT);
    s = SumHighestTrafficServers(*DS, -1, 5, &sum);
    assert(s == INVALID_INPUT);
    s = SumHighestTrafficServers(nullptr, 1, 5, &sum);
    assert(s == INVALID_INPUT);
    s = SumHighestTrafficServers(*DS, 1, 5, nullptr);
    assert(s == INVALID_INPUT);
    s = SumHighestTrafficServers(*DS, 1, 0, &sum);
    assert(s == SUCCESS && sum == 0);
    s = SumHighestTrafficServers(*DS, 0, 0, &sum);
    assert(s == SUCCESS && sum == 0);
    s = SetTraffic(nullptr, 3, 3);
    assert(s == INVALID_INPUT);
    s = SetTraffic(*DS, 0, 3);
    assert(s == INVALID_INPUT);
    s = SetTraffic(*DS, -1, 3);
    assert(s == INVALID_INPUT);
    s = SetTraffic(*DS, 1, -1);
    assert(s == INVALID_INPUT);
    s = SetTraffic(*DS, 5, -1);
    assert(s == INVALID_INPUT);
    s = SetTraffic(*DS, 11, 3);
    assert(s == FAILURE);
    s = SetTraffic(*DS, 1, 1);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 0, 1, &sum);
    assert(s == SUCCESS && sum == 1);
    s = SumHighestTrafficServers(*DS, 0, 0, &sum);
    assert(s == SUCCESS && sum == 0);
    s = SumHighestTrafficServers(*DS, 0, 12, &sum);
    assert(s == SUCCESS && sum == 1);
    s = SumHighestTrafficServers(*DS, 1, 0, &sum);
    assert(s == SUCCESS && sum == 0);
    s = SumHighestTrafficServers(*DS, 1, 1, &sum);
    assert(s == SUCCESS && sum == 1);
    s = SumHighestTrafficServers(*DS, 1, 2, &sum);
    assert(s == SUCCESS && sum == 1);
    s = SetTraffic(*DS, 2, 2);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 3, 3);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 4, 4);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 5, 5);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 2, 1, &sum);
    assert(s == SUCCESS && sum == 5);
    s = SumHighestTrafficServers(*DS, 2, 2, &sum);
    assert(s == SUCCESS && sum == 9);
    s = SumHighestTrafficServers(*DS, 2, 3, &sum);
    assert(s == SUCCESS && sum == 12);
    s = SumHighestTrafficServers(*DS, 2, 4, &sum);
    assert(s == SUCCESS && sum == 14);
    s = SetTraffic(*DS, 6, 6);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 7, 7);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 8, 8);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 9, 9);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 10, 10);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 3, 1, &sum);
    assert(s == SUCCESS && sum == 7);
    s = SumHighestTrafficServers(*DS, 3, 2, &sum);
    assert(s == SUCCESS && sum == 13);
    s = SumHighestTrafficServers(*DS, 3, 3, &sum);
    assert(s == SUCCESS && sum == 13);
    s = SumHighestTrafficServers(*DS, 4, 0, &sum);
    assert(s == SUCCESS && sum == 0);
    s = SumHighestTrafficServers(*DS, 4, 1, &sum);
    assert(s == SUCCESS && sum == 10);
    s = SumHighestTrafficServers(*DS, 4, 2, &sum);
    assert(s == SUCCESS && sum == 19);
    s = SumHighestTrafficServers(*DS, 4, 3, &sum);
    assert(s == SUCCESS && sum == 27);
    s = SumHighestTrafficServers(*DS, 0, 0, &sum);
    assert(s == SUCCESS && sum == 0);
    s = SumHighestTrafficServers(*DS, 0, 1, &sum);
    assert(s == SUCCESS && sum == 10);
    s = SumHighestTrafficServers(*DS, 0, 2, &sum);
    assert(s == SUCCESS && sum == 19);
    s = SumHighestTrafficServers(*DS, 0, 3, &sum);
    assert(s == SUCCESS && sum == 27);
    s = SumHighestTrafficServers(*DS, 0, 4, &sum);
    assert(s == SUCCESS && sum == 34);
    s = SumHighestTrafficServers(*DS, 0, 5, &sum);
    assert(s == SUCCESS && sum == 40);
    s = SumHighestTrafficServers(*DS, 0, 6, &sum);
    assert(s == SUCCESS && sum == 45);
    s = SumHighestTrafficServers(*DS, 0, 7, &sum);
    assert(s == SUCCESS && sum == 49);
    s = SumHighestTrafficServers(*DS, 0, 8, &sum);
    assert(s == SUCCESS && sum == 52);
    s = SumHighestTrafficServers(*DS, 0, 9, &sum);
    assert(s == SUCCESS && sum == 54);
    s = SumHighestTrafficServers(*DS, 0, 10, &sum);
    assert(s == SUCCESS && sum == 55);
    s = SumHighestTrafficServers(*DS, 0, 11, &sum);
    assert(s == SUCCESS && sum == 55);
    s = MergeDataCenters(*DS, 0, 2);
    assert(s == INVALID_INPUT);
    s = MergeDataCenters(*DS, 2, 0);
    assert(s == INVALID_INPUT);
    s = MergeDataCenters(*DS, 5, 2);
    assert(s == INVALID_INPUT);
    s = MergeDataCenters(*DS, 2, 5);
    assert(s == INVALID_INPUT);
    s = MergeDataCenters(*DS, -1, 2);
    assert(s == INVALID_INPUT);
    s = MergeDataCenters(*DS, 1, -2);
    assert(s == INVALID_INPUT);
    s = MergeDataCenters(nullptr, 1, 2);
    assert(s == INVALID_INPUT);
    s = MergeDataCenters(*DS, 1, 2);//check data_center_id of all servers which merged became 1 in the hash table!!!
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 1, 1, &sum);
    assert(s == SUCCESS && sum == 5);
    s = SumHighestTrafficServers(*DS, 1, 2, &sum);
    assert(s == SUCCESS && sum == 9);
    s = SumHighestTrafficServers(*DS, 1, 3, &sum);
    assert(s == SUCCESS && sum == 12);
    s = SumHighestTrafficServers(*DS, 1, 4, &sum);
    assert(s == SUCCESS && sum == 14);
    s = SumHighestTrafficServers(*DS, 1, 5, &sum);
    assert(s == SUCCESS && sum == 15);
    s = SumHighestTrafficServers(*DS, 2, 1, &sum);
    assert(s == SUCCESS && sum == 5);
    s = SumHighestTrafficServers(*DS, 2, 2, &sum);
    assert(s == SUCCESS && sum == 9);
    s = SumHighestTrafficServers(*DS, 2, 3, &sum);
    assert(s == SUCCESS && sum == 12);
    s = SumHighestTrafficServers(*DS, 2, 4, &sum);
    assert(s == SUCCESS && sum == 14);
    s = SumHighestTrafficServers(*DS, 2, 5, &sum);
    assert(s == SUCCESS && sum == 15);
    s = MergeDataCenters(*DS, 3, 2);// check id of main data_center is 1!
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 3, 1, &sum);
    assert(s == SUCCESS && sum == 7);
    s = SumHighestTrafficServers(*DS, 3, 2, &sum);
    assert(s == SUCCESS && sum == 13);
    s = SumHighestTrafficServers(*DS, 2, 3, &sum);
    assert(s == SUCCESS && sum == 18);
    s = SumHighestTrafficServers(*DS, 2, 4, &sum);
    assert(s == SUCCESS && sum == 22);
    s = SumHighestTrafficServers(*DS, 1, 5, &sum);
    assert(s == SUCCESS && sum == 25);
    s = SumHighestTrafficServers(*DS, 1, 6, &sum);
    assert(s == SUCCESS && sum == 27);
    s = SumHighestTrafficServers(*DS, 1, 7, &sum);
    assert(s == SUCCESS && sum == 28);
    s = SetTraffic(*DS, 2, 11);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 8, 11);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 6, 12);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 3, 1, &sum);
    assert(s == SUCCESS && sum == 12);
    s = SumHighestTrafficServers(*DS, 3, 2, &sum);
    assert(s == SUCCESS && sum == 23);
    //
    s = SumHighestTrafficServers(*DS, 3, 3, &sum);
    assert(s == SUCCESS && sum == 30);
    s = SumHighestTrafficServers(*DS, 3, 4, &sum);
    assert(s == SUCCESS && sum == 35);
    s = SumHighestTrafficServers(*DS, 3, 5, &sum);
    assert(s == SUCCESS && sum == 39);
    s = SumHighestTrafficServers(*DS, 3, 6, &sum);
    assert(s == SUCCESS && sum == 42);
    s = SumHighestTrafficServers(*DS, 2, 7, &sum);
    assert(s == SUCCESS && sum == 43);
    s = SumHighestTrafficServers(*DS, 0, 1, &sum);
    assert(s == SUCCESS && sum == 12);
    s = SumHighestTrafficServers(*DS, 0, 2, &sum);
    assert(s == SUCCESS && sum == 23);
    s = SumHighestTrafficServers(*DS, 0, 3, &sum);
    assert(s == SUCCESS && sum == 34);
    s = SumHighestTrafficServers(*DS, 0, 4, &sum);
    assert(s == SUCCESS && sum == 44);
    s = SumHighestTrafficServers(*DS, 0, 5, &sum);
    assert(s == SUCCESS && sum == 53);
    s = SumHighestTrafficServers(*DS, 0, 6, &sum);
    assert(s == SUCCESS && sum == 60);
    s = SumHighestTrafficServers(*DS, 0, 7, &sum);
    assert(s == SUCCESS && sum == 65);
    s = SumHighestTrafficServers(*DS, 0, 8, &sum);
    assert(s == SUCCESS && sum == 69);
    s = RemoveServer(*DS, 11);
    assert(s == FAILURE);
    s = RemoveServer(*DS, 0);
    assert(s == INVALID_INPUT);
    s = RemoveServer(*DS, -1);
    assert(s == INVALID_INPUT);
    s = RemoveServer(nullptr, 9);
    assert(s == INVALID_INPUT);
    s = RemoveServer(*DS, 2);//check server removed from hash table!
    assert(s == SUCCESS);
    s = RemoveServer(*DS, 4);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 3, 1, &sum);
    assert(s == SUCCESS && sum == 12);
    s = SumHighestTrafficServers(*DS, 3, 2, &sum);
    assert(s == SUCCESS && sum == 19);
    s = SumHighestTrafficServers(*DS, 3, 3, &sum);
    assert(s == SUCCESS && sum == 24);
    s = SumHighestTrafficServers(*DS, 2, 4, &sum);
    assert(s == SUCCESS && sum == 27);
    s = SumHighestTrafficServers(*DS, 1, 5, &sum);
    assert(s == SUCCESS && sum == 28);
    s = SumHighestTrafficServers(*DS, 1, 6, &sum);
    assert(s == SUCCESS && sum == 28);
    s = SumHighestTrafficServers(*DS, 2, 0, &sum);
    assert(s == SUCCESS && sum == 0);
    s = SumHighestTrafficServers(*DS, 0, 1, &sum);
    assert(s == SUCCESS && sum == 12);
    s = SumHighestTrafficServers(*DS, 0, 2, &sum);
    assert(s == SUCCESS && sum == 23);
    s = SumHighestTrafficServers(*DS, 0, 3, &sum);
    assert(s == SUCCESS && sum == 33);
    s = SumHighestTrafficServers(*DS, 0, 4, &sum);
    assert(s == SUCCESS && sum == 42);
    s = SumHighestTrafficServers(*DS, 0, 5, &sum);
    assert(s == SUCCESS && sum == 49);
    s = SumHighestTrafficServers(*DS, 0, 6, &sum);
    assert(s == SUCCESS && sum == 54);
    s = SumHighestTrafficServers(*DS, 0, 7, &sum);
    assert(s == SUCCESS && sum == 57);
    s = SumHighestTrafficServers(*DS, 0, 8, &sum);
    assert(s == SUCCESS && sum == 58);
    s = RemoveServer(*DS, 9);//check server removed from hash table+main_tree+(4)_tree!
    assert(s == SUCCESS);
    s = RemoveServer(*DS, 6);//check server removed from hash table+main_tree+(1,2,3)_tree!
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 1, 1, &sum);
    assert(s == SUCCESS && sum == 7);
    s = SumHighestTrafficServers(*DS, 1, 2, &sum);
    assert(s == SUCCESS && sum == 12);
    s = SumHighestTrafficServers(*DS, 3, 3, &sum);
    assert(s == SUCCESS && sum == 15);
    s = SumHighestTrafficServers(*DS, 2, 4, &sum);
    assert(s == SUCCESS && sum == 16);
    s = SumHighestTrafficServers(*DS, 0, 1, &sum);
    assert(s == SUCCESS && sum == 11);
    s = SumHighestTrafficServers(*DS, 0, 2, &sum);
    assert(s == SUCCESS && sum == 21);
    s = SumHighestTrafficServers(*DS, 0, 3, &sum);
    assert(s == SUCCESS && sum == 28);
    s = SumHighestTrafficServers(*DS, 0, 4, &sum);
    assert(s == SUCCESS && sum == 33);
    s = SumHighestTrafficServers(*DS, 0, 5, &sum);
    assert(s == SUCCESS && sum == 36);
    s = SumHighestTrafficServers(*DS, 0, 6, &sum);
    assert(s == SUCCESS && sum == 37);
    s = RemoveServer(*DS, 3);
    assert(s == SUCCESS);
    s = RemoveServer(*DS, 8);
    assert(s == SUCCESS);
    s = RemoveServer(*DS, 7);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 2, 0, &sum);
    assert(s == SUCCESS && sum == 0);
    s = SumHighestTrafficServers(*DS, 1, 1, &sum);
    assert(s == SUCCESS && sum == 5);
    s = SumHighestTrafficServers(*DS, 3, 2, &sum);
    assert(s == SUCCESS && sum == 6);
    s = SumHighestTrafficServers(*DS, 4, 3, &sum);
    assert(s == SUCCESS && sum == 10);
    s = SumHighestTrafficServers(*DS, 0, 1, &sum);
    assert(s == SUCCESS && sum == 10);
    s = SumHighestTrafficServers(*DS, 0, 2, &sum);
    assert(s == SUCCESS && sum == 15);
    s = SumHighestTrafficServers(*DS, 0, 3, &sum);
    assert(s == SUCCESS && sum == 16);
    s = RemoveServer(*DS, 3);
    assert(s == FAILURE);
    s = RemoveServer(*DS, 1);
    assert(s == SUCCESS);
    s = RemoveServer(*DS, 5);
    assert(s == SUCCESS);
    s = RemoveServer(*DS, 10);//check main_tree+(1,2,3)_tree+(4)_tree+hash table are empty!
    assert(s == SUCCESS);
    s = AddServer(*DS, 1, 1);//check server 1 was inserted to hash table!
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 1, 5);//check server 1 was inserted to (1,2,3)_tree+main_tree!
    assert(s == SUCCESS);

    Quit(DS);
    delete DS;

    cout << "***************~~~~~~~~~~~~~~~~~~~~~~~~~***************" << "\n";
    cout << "**********~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~**********" << "\n";
    cout << "*****~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*****" << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~CONGRATULATIONS~~~~~~~~~~~~~~~~~~~~" << "\n";
    cout << "*****~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*****" << "\n";
    cout << "**********~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~**********" << "\n";
    cout << "***************~~~~~~~~~~~~~~~~~~~~~~~~~***************" << "\n";

//
//    void** DS=new (void*);
//    *DS=Init(10);
//    assert(*DS!=NULL);
//    StatusType s=AddServer(*DS,11,10);
//    assert(s==INVALID_INPUT);
//    s=AddServer(*DS,0,10);
//    assert(s==INVALID_INPUT);
//    s=AddServer(*DS,-1,10);
//    assert(s==INVALID_INPUT);
//    s=AddServer(*DS,5,0);
//    assert(s==INVALID_INPUT);
//    s=AddServer(*DS,5,-44);
//    assert(s==INVALID_INPUT);
//    s=AddServer(nullptr,5,-44);
//    assert(s==INVALID_INPUT);
//    s=AddServer(*DS,5,1);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,5,1);
//    assert(s==FAILURE);
//    s=AddServer(*DS,1,1);
//    assert(s==FAILURE);
//    s=AddServer(*DS,1,2);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,1,3);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,2,3);
//    assert(s==FAILURE);
//    s=AddServer(*DS,2,4);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,10,5);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,10,6);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,9,6);
//    assert(s==FAILURE);
//    s=AddServer(*DS,9,7);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,9,8);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,8,9);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,8,10);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,8,11);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,7,12);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,7,13);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,6,14);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,5,15);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,5,16);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,4,17);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,4,18);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,3,19);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,3,20);
//    assert(s==SUCCESS);
//    s=RemoveServer(*DS,4);
//    assert(s==SUCCESS);
//    s=RemoveServer(*DS,4);
//    assert(s==FAILURE);
//    s=RemoveServer(*DS,10);
//    assert(s==SUCCESS);
//    s=RemoveServer(*DS,21);
//    assert(s==FAILURE);
//    s=RemoveServer(*DS,0);
//    assert(s==INVALID_INPUT);
//    s=RemoveServer(nullptr,9);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(nullptr,3,3);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,0,3);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,-1,3);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,21,3);
//    assert(s==FAILURE);
//    s=SetTraffic(*DS,4,3);
//    assert(s==FAILURE);
//    s=SetTraffic(*DS,10,3);
//    assert(s==FAILURE);
//    s=SetTraffic(*DS,1,-1);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,5,-1);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,10,-1);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,9,-1);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,4,-1);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,14,-1);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,14,5);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,20,11);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,3,11);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,2,3);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,6,4);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,13,7);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,18,25);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,16,12);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,12,12);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,7,5);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,8,5);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,8,10);
//    assert(s==SUCCESS);
//    int sum=0;
//    s=SumHighestTrafficServers(nullptr,5,1,&sum);
//    assert(s==INVALID_INPUT);
//    s=SumHighestTrafficServers(*DS,5,-1,&sum);
//    assert(s==INVALID_INPUT);
//    s=SumHighestTrafficServers(*DS,21,1,&sum);
//    assert(s==INVALID_INPUT);
//    s=SumHighestTrafficServers(*DS,-1,1,&sum);
//    assert(s==INVALID_INPUT);
//    s=SumHighestTrafficServers(*DS,0,1,&sum);
//    assert(s==SUCCESS && sum==25);
//    s=SumHighestTrafficServers(*DS,0,3,&sum);
//    assert(s==SUCCESS && sum==49);
//    s=SumHighestTrafficServers(*DS,0,5,&sum);
//    assert(s==SUCCESS && sum==71);
//    s=SetTraffic(*DS,3,2);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,0,5,&sum);
//    assert(s==SUCCESS && sum==70);
//    s=SetTraffic(*DS,9,21);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,0,5,&sum);
//    assert(s==SUCCESS && sum==81);
//    s=SumHighestTrafficServers(*DS,5,3,&sum);
//    assert(s==SUCCESS && sum==12);
//    s=SetTraffic(*DS,15,2);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,5,3,&sum);
//    assert(s==SUCCESS && sum==14);
//    s=SetTraffic(*DS,1,1);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,5,3,&sum);
//    assert(s==SUCCESS && sum==15);
//    s=MergeDataCenters(nullptr,5,2);
//    assert(s==INVALID_INPUT);
//    s=MergeDataCenters(*DS,4,0);
//    assert(s==INVALID_INPUT);
//    s=MergeDataCenters(*DS,0,4);
//    assert(s==INVALID_INPUT);
//    s=MergeDataCenters(*DS,21,4);
//    assert(s==INVALID_INPUT);
//    s=MergeDataCenters(*DS,4,23);
//    assert(s==INVALID_INPUT);
//    s=MergeDataCenters(*DS,4,5);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,4,3,&sum);
//    assert(s==SUCCESS && sum==39);
//    s=SumHighestTrafficServers(*DS,5,3,&sum);
//    assert(s==SUCCESS && sum==39);
//    s=SetTraffic(*DS,16,8);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,5,3,&sum);
//    assert(s==SUCCESS && sum==35);
//    s=SumHighestTrafficServers(*DS,5,1,&sum);
//    assert(s==SUCCESS && sum==25);
//    s=SumHighestTrafficServers(*DS,5,2,&sum);
//    assert(s==SUCCESS && sum==33);
//    s=SumHighestTrafficServers(*DS,5,4,&sum);
//    assert(s==SUCCESS && sum==36);
//    s=SumHighestTrafficServers(*DS,5,5,&sum);
//    assert(s==SUCCESS && sum==36);
//    s=SumHighestTrafficServers(*DS,4,3,&sum);
//    assert(s==SUCCESS && sum==35);
//    s=SumHighestTrafficServers(*DS,4,1,&sum);
//    assert(s==SUCCESS && sum==25);
//    s=SumHighestTrafficServers(*DS,4,2,&sum);
//    assert(s==SUCCESS && sum==33);
//    s=SumHighestTrafficServers(*DS,4,4,&sum);
//    assert(s==SUCCESS && sum==36);
//    s=SumHighestTrafficServers(*DS,4,5,&sum);
//    assert(s==SUCCESS && sum==36);
//    s=AddServer(*DS,4,10);
//    assert(s==SUCCESS );
//    s=SetTraffic(*DS,10,30);
//    assert(s==SUCCESS );
//    s=SumHighestTrafficServers(*DS,4,2,&sum);
//    assert(s==SUCCESS && sum==55);
//    s=SumHighestTrafficServers(*DS,5,2,&sum);
//    assert(s==SUCCESS && sum==55);
//    s=MergeDataCenters(*DS,4,9);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,8,60);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,4,1,&sum);
//    assert(s==SUCCESS && sum==60);
//    s=SumHighestTrafficServers(*DS,5,1,&sum);
//    assert(s==SUCCESS && sum==60);
//    s=SumHighestTrafficServers(*DS,9,1,&sum);
//    assert(s==SUCCESS && sum==60);
//    s=SumHighestTrafficServers(*DS,4,2,&sum);
//    assert(s==SUCCESS && sum==90);
//    s=SumHighestTrafficServers(*DS,5,2,&sum);
//    assert(s==SUCCESS && sum==90);
//    s=SumHighestTrafficServers(*DS,9,2,&sum);
//    assert(s==SUCCESS && sum==90);
//    s=SumHighestTrafficServers(*DS,5,4,&sum);
//    assert(s==SUCCESS && sum==123);
//    s=SumHighestTrafficServers(*DS,0,1,&sum);
//    assert(s==SUCCESS && sum==60);
//    s=SumHighestTrafficServers(*DS,0,3,&sum);
//    assert(s==SUCCESS && sum==115);
//    s=RemoveServer(*DS,8);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,5,1,&sum);
//    assert(s==SUCCESS && sum==30);
//    s=SetTraffic(*DS,7,100);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,0,1,&sum);
//    assert(s==SUCCESS && sum==100);
//    s=SumHighestTrafficServers(*DS,5,1,&sum);
//    assert(s==SUCCESS && sum==100);
//    s=SumHighestTrafficServers(*DS,5,2,&sum);
//    assert(s==SUCCESS && sum==130);
//    s=SumHighestTrafficServers(*DS,9,2,&sum);
//    assert(s==SUCCESS && sum==130);
//    s=SumHighestTrafficServers(*DS,4,2,&sum);
//    assert(s==SUCCESS && sum==130);
//    s=SumHighestTrafficServers(*DS,5,6,&sum);
//    assert(s==SUCCESS && sum==166);
//    s=SumHighestTrafficServers(*DS,4,6,&sum);
//    assert(s==SUCCESS && sum==166);
//    s=SumHighestTrafficServers(*DS,9,6,&sum);
//    assert(s==SUCCESS && sum==166);
//    Quit(DS);
//    delete DS;
//    cout<<"*******************************************************"<<"\n";
//    cout<<"*******************************************************"<<"\n";
//    cout<<"YOU HAVE PASSED THE TEST ^___^"<<"\n"<<"GOOD LUCK IN THE FINAL EXAM";
//    cout<<"\n"<<"*******************************************************"<<"\n";
//    cout<<"*******************************************************"<<"\n";
}

