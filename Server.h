//
// Created by Akiva on 2019-12-26.
//

#ifndef DATACENTERSMANAGER2_SERVER_H
#define DATACENTERSMANAGER2_SERVER_H

#include "Data Structures/Set.h"

class Server { //TODO:INCOMPLETE!
private: //DEBUGGING NOTE: Make public to be able to run the test currently in main
    unsigned int traffic = 0;
public:
    void setTraffic(unsigned int traffic);

private:
    Set<Server>::SetNode link;

public:
    bool operator>(const Server &other);
};

bool Server::operator>(const Server &other) {
    return traffic > other.traffic;
}

void Server::setTraffic(unsigned int traffic) {
    Server::traffic = traffic;
}

#endif //DATACENTERSMANAGER2_SERVER_H
