//
// Created by Akiva on 2020-01-13.
//

#include "DataCenterManager.h"
#include "library2.h"

void *Init(int n) {
    return new DataCenterManager(n);
}

StatusType MergeDataCenters(void *DS, int dataCenter1, int dataCenter2) {
    if (DS == nullptr) return INVALID_INPUT;
    int n = ((DataCenterManager *) DS)->getDataCentersSize();
    if (dataCenter2 <= 0 || dataCenter2 > n || dataCenter1 <= 0 || dataCenter1 > n) return INVALID_INPUT;
    try {
        return (StatusType) ((DataCenterManager *) DS)->MergeDataCenters(dataCenter1, dataCenter2);
    } catch (std::bad_alloc &ba) {
        return ALLOCATION_ERROR;
    }
}

StatusType AddServer(void *DS, int dataCenterID, int serverID) {
    if (DS == nullptr) return INVALID_INPUT;
    int n = ((DataCenterManager *) DS)->getDataCentersSize();
    if (serverID <= 0 || dataCenterID <= 0 || dataCenterID > n) return INVALID_INPUT;
    try {
        return (StatusType) ((DataCenterManager *) DS)->AddServer(dataCenterID, serverID);
    } catch (std::bad_alloc &ba) {
        return ALLOCATION_ERROR;
    }
}

StatusType RemoveServer(void *DS, int serverID) {
    if (DS == nullptr) return INVALID_INPUT;
    if (serverID <= 0) return INVALID_INPUT;
    try {
        return (StatusType) ((DataCenterManager *) DS)->RemoveServer(serverID);
    } catch (std::bad_alloc &ba) {
        return ALLOCATION_ERROR;
    }
}

StatusType SetTraffic(void *DS, int serverID, int traffic) {
    if (DS == nullptr) return INVALID_INPUT;
    if (serverID <= 0 || traffic < 0) return INVALID_INPUT;
    try {
        return (StatusType) ((DataCenterManager *) DS)->SetTraffic(serverID, traffic);
    } catch (std::bad_alloc &ba) {
        return ALLOCATION_ERROR;
    }
}

StatusType SumHighestTrafficServers(void *DS, int dataCenterID, int k, int *traffic) {
    if (DS == nullptr) return INVALID_INPUT;
    int n = ((DataCenterManager *) DS)->getDataCentersSize();
    if (traffic == nullptr || dataCenterID < 0 || dataCenterID > n || k < 0) return INVALID_INPUT;
    try {
        return (StatusType) ((DataCenterManager *) DS)->SumHighestTrafficServers(dataCenterID, k, traffic);
    } catch (std::bad_alloc &ba) {
        return ALLOCATION_ERROR;
    }
}

void Quit(void **DS) {
    if (!DS) return;
    delete ((DataCenterManager *) *DS);
    *DS = nullptr;
}
