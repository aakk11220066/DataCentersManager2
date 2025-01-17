//
// Created by Roy on 30/12/19.
//

#ifndef DATACENTERSMANAGER2_DATACENTER_H
#define DATACENTERSMANAGER2_DATACENTER_H
#include "Data Structures/AVLTree/AVLTree.h"
#include "Server.h"


class DataCenter {
public:
    DataCenter &merge(DataCenter &other) {
        servers_num += other.servers_num;
        servers_tree = servers_tree.merge(other.servers_tree);
        return *this;
    }

    int id;

    void setID(int given_id) {
        DataCenter::id = given_id;
    }

    int servers_num;
    AVLTree<Server> servers_tree;
    enum DataCenterError {
        SUCCESS = 0, FAILURE = -1, ALLOCATION_ERROR = -2, INVALID_INPUT = -3
    };
public:
    //ctor
    explicit DataCenter(int given_id = 0) : id(given_id), servers_num(3) {}

    void IncrementSize() { servers_num++; }

    void DecrementSize() { servers_num--; }//AKIVA

    DataCenterError AddServer(int given_id) {
        //check in outer layers that the id is correct
        //check in outer layer that id isn;t already inside HashTable
        Server temp_server(given_id);
        try {
            servers_tree.insert(temp_server);
            return SUCCESS;
        }
        catch (DataManagerExceptions::Exceptions &e) {
            return FAILURE;
        }
    }

    void RemoveServer(const Server &targetServer) {
        //check in outer layers that the id is correct
        try {
            servers_num--;
            servers_tree.remove(targetServer);
            return;
        }
        catch (DataManagerExceptions::Exceptions &e) {
            return;
        }
    }

    void SetTraffic(const Server &server, int new_traffic) {
        //check in traffic and server number are legal
        //check server in hash table
        Server old_server(server.getID(), server.getTraffic(), id);
        try {
            servers_tree.remove(old_server);
        } catch (DataManagerExceptions::ObjectUnfound &e) {}
        Server new_server(server.getID(), new_traffic, id);
        servers_tree.insert(new_server);
        //servers_tree.insert(temp_server);
    }

    DataCenterError SumHighestTrafficServers(int k, int *traffic) {
        int tree_size = servers_tree.getTreeSize();
        if (k > tree_size) k = tree_size; //AKIVA
        if (k == 0) { //AKIVA
            *traffic = 0;
            return SUCCESS;
        }
        Server max_server = servers_tree[tree_size-1];
        if (k >= tree_size) {
            *traffic = servers_tree.getPartialSum(max_server);
            return SUCCESS;
        } else {
            k = tree_size - k;
            Server kth_server = servers_tree[k-1];
            int sumOfTree = servers_tree.getPartialSum(max_server);
            int partialSumUpToK = servers_tree.getPartialSum(kth_server);
            *traffic = sumOfTree - partialSumUpToK;
            return SUCCESS;
        }
    };

};

#endif //DATACENTERSMANAGER2_DATACENTER_H
