//
// Created by Akiva on 2020-01-13.
//

#ifndef DATACENTERSMANAGER2_CINTERFACE_H
#define DATACENTERSMANAGER2_CINTERFACE_H

#include "DataCenterManager.h"

enum StatusType {
    SUCCESS = DataCenterManager::DataCenterManagerError::SUCCESS,
    ALLOCATION_ERROR = DataCenterManager::DataCenterManagerError::ALLOCATION_ERROR,
    INVALID_INPUT = DataCenterManager::DataCenterManagerError::INVALID_INPUT,
    FAILURE = DataCenterManager::DataCenterManagerError::FAILURE
};

void *Init(int n);

StatusType MergeDataCenters(void *DS, int dataCenter1, int dataCenter2);

StatusType AddServer(void *DS, int dataCenterID, int serverID);

StatusType RemoveServer(void *DS, int serverID);

StatusType SetTraffic(void *DS, int serverID, int traffic);

StatusType SumHighestTrafficServers(void *DS, int dataCenterID, int k, int *traffic);

void Quit(void **DS);


#endif //DATACENTERSMANAGER2_CINTERFACE_H
