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
//we may also need to verify that the conversion from aux_server to server slices the fields correctly.
//UF section is verified..
//AVL rank tree needs to support abstract_datatypes, it fails with the servers
//we need to implement +operator for server

//NOTE: HT doesn't throw "NotFound" error, in such case it return AuxServer with (illegal) id which i've set to 0).

//now all that's left is handling with tree's enhancements, including merging 2 datacenters via empty AVL tree.

class DataCenterManager {
private:
    int dataCentersSize;
    UnionFind dataCentersUF;
    DataCenter* dataCentersArray;
    HashTable serversHT;
    AVLTree<Server> serversTree;
    enum DataCenterManagerError{SUCCESS = 0, FAILURE = -1, ALLOCATION_ERROR = -2, INVALID_INPUT = -3};
public:
   explicit DataCenterManager(int size): dataCentersSize(size), dataCentersUF(size){
       dataCentersArray = new DataCenter[size];
       for (int i =1; i <= size; i++){
           dataCentersArray[i].setID(i);
       }
   }
   ~DataCenterManager(){
       delete[] dataCentersArray;
   }
   DataCenterManagerError MergeDataCeneters(int dataCenter1, int dataCenter2) {
       if (dataCenter1 > dataCentersSize || dataCenter2 > dataCentersSize)
           return INVALID_INPUT;
       int dc1_head = dataCentersUF.find(dataCenter1);
       int dc2_head = dataCentersUF.find(dataCenter2);
       //try block to catch allocation error
       try {
           dataCentersArray[dc1_head].merge(dc2_head);
           return SUCCESS;
       }
       catch(DataManagerExceptions::Exceptions &e){
           return ALLOCATION_ERROR;
       }
   }
   DataCenterManagerError AddServer(int DataCenterID, int ServerID){
       if (DataCenterID > dataCentersSize) return INVALID_INPUT;
       int dc_head = dataCentersUF.find(DataCenterID);
       ServerAux sa_temp(ServerID,0,dc_head);
       if (serversHT.find(sa_temp).getID() == 0){
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
       int dc_head = dataCentersUF.find(server_dc_id);
       dataCentersArray[dc_head].DecrementSize();
       if (sa_result.getTraffic() > 0){
           dataCentersArray[dc_head].RemoveServer(ServerID);
           serversTree.remove(sa_result);
       }
       return SUCCESS;
   }

   DataCenterManagerError SetTraffic(int ServerID, int trafficID){
       //check traffic and server are legal....
       ServerAux sa_temp(ServerID);
       ServerAux sa_result = serversHT.find(sa_temp);
       if (sa_result.getID() == 0){
           return FAILURE;
       }
       int server_dc_id = sa_result.getDCID();
       int dc_head = dataCentersUF.find(server_dc_id);
       dataCentersArray[dc_head].SetTraffic(ServerID,trafficID);
       serversTree.remove(sa_result);
       serversTree.insert(sa_result);
       return SUCCESS;
   }

   DataCenterManagerError SumHighestTrafficServers(int dataCenterID, int k, int *traffic){
       //check variables validity...
       if (dataCenterID > dataCentersSize) return INVALID_INPUT;
       if (dataCenterID == 0){
           //copied from the respective function in DataCenter

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

       }
       else{
           //check no negative numbers sneak in here
           int dc_head = dataCentersUF.find(dataCenterID);
           dataCentersArray[dc_head].SumHighestTrafficServers(k, traffic);
       }
       return SUCCESS;

   }
};



/*
public:
    void MergeDataCenters(void *DS, int dataCenter1, int dataCenter2);
};

void DataCenterManager::MergeDataCenters(void *DS, int dataCenter1, int dataCenter2) {
    dataCenters[dataCenter1] = dataCenters[dataCenter1].merge(dataCenters[dataCenter2]);
}
*/

#endif //DATACENTERSMANAGER2_DATACENTERMANAGER_H
