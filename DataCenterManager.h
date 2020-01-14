//
// Created by Akiva on 2019-12-31.
//

#ifndef DATACENTERSMANAGER2_DATACENTERMANAGER_H
#define DATACENTERSMANAGER2_DATACENTERMANAGER_H

#include "DataCenter.h"
#include "Data Structures/AVLTree/AVLTree.h"
#include "HashTable"
#include "Server.h"
#include "Data Structures/UnionFind.h"
// we may need to wrap up some lines with try-catch in order to handling allocation errors

class DataCenterManager {
private:
    const int dataCentersSize;
public:
    int getDataCentersSize() const {
        return dataCentersSize;
    }

private:
    UnionFind dataCentersUF;
    DataCenter *dataCentersArray; //Array<DataCenter> would be better...
    HashTable serversHT;
    AVLTree<Server> serversTree;
public:
    enum DataCenterManagerError{SUCCESS = 0, FAILURE = -1, ALLOCATION_ERROR = -2, INVALID_INPUT = -3};
public:
   explicit DataCenterManager(int size): dataCentersSize(size), dataCentersUF(size){
       dataCentersArray = new DataCenter[size];
       for (int i =0; i < size; i++){
           dataCentersArray[i].setID(i);
       }
   }
   ~DataCenterManager(){
       delete[] dataCentersArray;
   }
   DataCenterManagerError MergeDataCenters(int dataCenter1, int dataCenter2) {
       if (dataCenter1 > dataCentersSize || dataCenter2 > dataCentersSize)
           return INVALID_INPUT;
       int dc1_head = dataCentersUF.find(dataCenter1);
       int dc2_head = dataCentersUF.find(dataCenter2);
       //try block to catch allocation error
       try {
           dataCentersArray[dc1_head].merge(dataCentersArray[dc2_head]);
           dataCentersUF.unite(dataCenter1, dataCenter2); //AKIVA
           return SUCCESS;
       }
       catch(DataManagerExceptions::Exceptions &e){
           return ALLOCATION_ERROR;
       }
   }
   DataCenterManagerError AddServer(int DataCenterID, int ServerID){
       if (DataCenterID > dataCentersSize) return INVALID_INPUT;
       int dc_head = dataCentersUF.find(DataCenterID-1);
       //printf("headdd is %d", dc_head);
       ServerAux sa_temp(ServerID, 0, dc_head);
       if (serversHT.find(sa_temp).getID() != 0){
           //this means the server already exists
           return FAILURE;
       }
       //check for allocation error
       serversHT.add(sa_temp);
       dataCentersArray[dc_head].IncrementSize();
       return SUCCESS;
   }

   DataCenterManagerError RemoveServer(int ServerID){
       ServerAux sa_temp(ServerID);
       ServerAux sa_result = serversHT.find(sa_temp);
       if (sa_result.getID() == 0){
           return FAILURE;
       }
       serversHT.remove(sa_result);
       int server_dc_id = sa_result.getDCID();
       //int server_dc_id = sa_result.getID(); //AKIVA: replaced commented-out line with this one
       int dc_head = dataCentersUF.find(server_dc_id);
       dataCentersArray[dc_head].DecrementSize();
       if (sa_result.getIsInTree()) {
           dataCentersArray[dc_head].RemoveServer(ServerID);
           serversTree.remove(sa_result);
       }
       return SUCCESS;
   }

    DataCenterManagerError SetTraffic(int ServerID, int traffic) {
       //check traffic and server are legal....
       ServerAux sa_temp(ServerID);
       ServerAux sa_result = serversHT.find(sa_temp);
        /*if (!sa_result.getIsInTree()) {
           return FAILURE;
       }*/
       int server_dc_id = sa_result.getDCID();
        //printf("dc_d is %d\n", server_dc_id);
       //int server_dc_id = sa_result.getID(); //AKIVA: replaced commented-out line with this one
       int dc_head = dataCentersUF.find(server_dc_id);
        //printf("head is %d\n", dc_head);
        dataCentersArray[dc_head].SetTraffic(sa_result, traffic);
        if (sa_result.getIsInTree()) serversTree.remove(sa_result);
        sa_result.setIsInTree(true);
       sa_result.setTraffic(traffic);
       serversTree.insert(sa_result);
       return SUCCESS;
   }

   DataCenterManagerError SumHighestTrafficServers(int dataCenterID, int k, int *traffic){
       //check variables validity...
       if (dataCenterID > dataCentersSize) return INVALID_INPUT;
       if (dataCenterID == 0) {
           //copied from the respective function in DataCenter

           //if (k > dataCentersSize) return FAILURE; //
           int tree_size = serversTree.getTreeSize(); //AKIVA: replaced servers_tree with serversTree (including later mentions in this function)
           Server max_server = serversTree[tree_size-1]; //AKIVA: replaced getMaxNode with [tree_size]
           if (k >= tree_size) {
               *traffic = serversTree.getPartialSum(max_server);
               return SUCCESS;
           } else {
               k = tree_size - k;
               Server kth_server = serversTree[k-1]; //AKIVA: replaced getKthNode with operator[]
               *traffic = serversTree.getPartialSum(max_server) - serversTree.getPartialSum(kth_server);
           }
       }
       else{
           //check no negative numbers sneak in here
           int dc_head = dataCentersUF.find(dataCenterID-1);
           dataCentersArray[dc_head].SumHighestTrafficServers(k, traffic);
       }
       return SUCCESS;
   }
};


#endif //DATACENTERSMANAGER2_DATACENTERMANAGER_H
