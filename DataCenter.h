//
// Created by Roy on 30/12/19.
//

#ifndef DATACENTERSMANAGER2_DATACENTER_H
#define DATACENTERSMANAGER2_DATACENTER_H
#include "Data Structures/AVLTree/AVLTree.h"
#include "Server.h"


class DataCenter  { //Roi's version
private: //DEBUGGING NOTE: Make public to be able to run the test currently in main
    int id;
    int servers_num;
    AVLTree<Server> servers_tree;
    enum DataCenterError{SUCCESS = 0, FAILURE = -1, ALLOCATION_ERROR = -2, INVALID_INPUT = -3};
public:
    //ctor
    explicit DataCenter(int given_id = 0) : id(given_id), servers_num(0) {}
    void setID(int given_id) {id = given_id;}
    void IncrementSize() {servers_num++;}
    void DecrementSize() {servers_num--;}
    DataCenterError AddServer(int given_id){
        //check in outer layers that the id is correct
        //check in outer layer that id isn;t already inside HashTable
        Server temp_server(given_id);
        try {
            servers_tree.insert(temp_server);
            return SUCCESS;
        }
        catch (DataManagerExceptions::Exceptions &e){
            return FAILURE;
        }
    }

    DataCenterError RemoveServer(int ServerID){
        //check in outer layers that the id is correct
        Server temp_server(ServerID);
        try {
            servers_tree.remove(temp_server);
            return SUCCESS;
        }
        catch (DataManagerExceptions::Exceptions &e){
            return FAILURE;
        }
    }

    DataCenterError SetTraffic(int ServerID, int traffic){
        //check in traffic and server number are legal
        //check server in hash table
        Server temp_server(ServerID, traffic);
        servers_tree.remove(temp_server);
        servers_tree.insert(temp_server);
    }

    DataCenterError SumHighestTrafficServers(int k, int *traffic){
     //check k> 0
     //if (k > servers_num) return FAILURE;
     //int tree_size = servers_tree.getTreeSize();
     //Server max_server = servers_tree.getMaxNode();
     //if (k >= tree_size) {
     //    *traffic = servers_tree.getPartialSum(max_server);
     //    return SUCCESS;
     //}
     //else{
     //    k = tree_size - k;
     //    Server kth_server = servers_tree.getKthNode();
     //    *traffic = servers_tree.getPartialSum(max_server) - servers_tree.getPartialSum(kth_server);
         return SUCCESS;
     }
     //

};
/*
DataCenter &DataCenter::merge(DataCenter &other) {
    servers_tree = servers_tree.merge(other.servers_tree);
    this->setsUnion(other);
    return *this;
}
*/
#endif //DATACENTERSMANAGER2_DATACENTER_H
