//
// Created by Akiva on 2019-12-26.
//

#ifndef DATACENTERSMANAGER2_SERVER_H
#define DATACENTERSMANAGER2_SERVER_H

#include "Data Structures/Set.h"

class Server { //TODO:INCOMPLETE!
private: //DEBUGGING NOTE: Make public to be able to run the test currently in main
    unsigned int traffic = 0;
    Set<Server>::SetNode link;
};

#endif //DATACENTERSMANAGER2_SERVER_H
