//
// Created by Akiva on 2019-12-26.
//

#ifndef DATACENTERSMANAGER2_SERVER_H
#define DATACENTERSMANAGER2_SERVER_H


class DataCenter;

class Server { //Roi's version
private:

    DataCenter &getContainingDataCenter();

protected: //DEBUGGING NOTE: Make public to be able to run the test currently in main
    int id;
    int traffic;
    int dc_id;
public:
    explicit Server(int given_id = 0, int given_traffic = 0, int given_dc_id = 0) :
            id(given_id), traffic(given_traffic), dc_id(given_dc_id) {
    }
    //destructor
    virtual ~Server()= default;
    void setTraffic(int given_traffic) { traffic = given_traffic;}
    int getTraffic() const {return traffic;}
    int getID() const {return id;}
    int getDCID() const {return dc_id;}
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

    int operator+(const Server &server2) const {
        return traffic + server2.traffic;
    }
};


class ServerAux: public Server {
public:
    ~ServerAux() override = default;
    bool operator> (const Server &server) const override {
        return id>server.getID();
    }

public:
    explicit ServerAux(int given_id = 0, int given_traffic = 0, int given_dc_id = 0): Server(given_id,given_traffic){};
};

#endif //DATACENTERSMANAGER2_SERVER_H
