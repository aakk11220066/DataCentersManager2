//
// Created by Akiva on 2019-12-30.
//

#ifndef DATACENTERSMANAGER2_DATACENTER_H
#define DATACENTERSMANAGER2_DATACENTER_H

#include "Data Structures/Set.h"
#include "Data Structures/AVLTree/AVLTree.h"
#include "Server.h"

class DataCenter : public Set<Server> {
private:
    AVLTree<Server> DCServers;
public:
    DataCenter &merge(DataCenter<T> &);
};

#endif //DATACENTERSMANAGER2_DATACENTER_H
