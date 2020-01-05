//
// Created by Akiva on 2019-12-31.
//

#ifndef DATACENTERSMANAGER2_DATACENTERMANAGER_H
#define DATACENTERSMANAGER2_DATACENTERMANAGER_H

#include "DataCenter.h"
#include "Data Structures/AVLTree/AVLTree.h"

class DataCenterManager {
private:
    Array<DataCenter> dataCenters;
    AVLTree<Server> serversTraffic;

public:
    void MergeDataCenters(void *DS, int dataCenter1, int dataCenter2);
};

void DataCenterManager::MergeDataCenters(void *DS, int dataCenter1, int dataCenter2) {
    dataCenters[dataCenter1] = dataCenters[dataCenter1].merge(dataCenters[dataCenter2]);
}


#endif //DATACENTERSMANAGER2_DATACENTERMANAGER_H
