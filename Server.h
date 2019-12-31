//
// Created by Akiva on 2019-12-26.
//

#ifndef DATACENTERSMANAGER2_SERVER_H
#define DATACENTERSMANAGER2_SERVER_H

#include "Data Structures/Set.h"
/*
class Server { //TODO:INCOMPLETE!
public: //DEBUGGING NOTE: Make public to be able to run the test currently in main
    unsigned int traffic = 0;
    Set<Server>::SetNode link;
};
*/

class Server { //Roi's version
protected: //DEBUGGING NOTE: Make public to be able to run the test currently in main
    int id;
    int traffic;
public:
    explicit Server(int given_id = 0, int given_traffic = 0): id(given_id), traffic(given_traffic) {}
    //destructor
    virtual ~Server()= default;
    void setTraffic(int given_traffic) { traffic = given_traffic;}
    int getTraffic() const {return traffic;}
    int getID() const {return id;}
    //operators
    bool operator==(const Server &server) const {
        return (server.id == id);
    }
    virtual bool operator> (const Server &server) const {
        if (traffic > server.traffic) return true;
        if (traffic < server.traffic) return false;
        if (traffic == server.traffic){
            return id > server.id;
        }
        return false;
    }
};


class ServerAux: public Server {
public:
    ~ServerAux() override = default;
    bool operator> (const Server &server) const override {
        return id>server.getID();
    }

public:
    explicit ServerAux(int given_id = 0, int given_traffic = 0): Server(given_id,given_traffic){};
};

#endif //DATACENTERSMANAGER2_SERVER_H
