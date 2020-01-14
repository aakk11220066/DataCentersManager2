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

    DataCenterError RemoveServer(int ServerID) {
        //check in outer layers that the id is correct
        Server temp_server(ServerID);
        try {
            servers_tree.remove(temp_server);
            servers_num--;
            return SUCCESS;
        }
        catch (DataManagerExceptions::Exceptions &e) {
            return FAILURE;
        }
    }

    void SetTraffic(const Server &server, int new_traffic) {
        //check in traffic and server number are legal
        //check server in hash table
        Server old_server(server.getID(), server.getTraffic(), id);
        if (server.getIsInTree()) servers_tree.remove(old_server);
        Server new_server(server.getID(), new_traffic, id);
        new_server.setIsInTree(true);
        servers_tree.insert(new_server);
        //servers_tree.insert(temp_server);
    }

    DataCenterError SumHighestTrafficServers(int k, int *traffic) {
        if (k == 0) { //AKIVA
            *traffic = 0;
            return SUCCESS;
        }
        if (k > servers_num) k = servers_num; //AKIVA
        int tree_size = servers_tree.getTreeSize();
        Server max_server = servers_tree[tree_size-1];
        if (k >= tree_size) {
            *traffic = servers_tree.getPartialSum(max_server);
            return SUCCESS;
        } else {
            k = tree_size - k;
            Server kth_server = servers_tree[k-1];
            *traffic = servers_tree.getPartialSum(max_server) - servers_tree.getPartialSum(kth_server);
            return SUCCESS;
        }
    };

};

#endif //DATACENTERSMANAGER2_DATACENTER_H
