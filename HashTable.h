#ifndef DATACENTERSMANAGER2_HASHTABLE_H
#define DATACENTERSMANAGER2_HASHTABLE_H
#include "Data Structures/AVLTree/AVLTree.h"
#include <random>
#include "Server.h"
class HashTable{
private:
    const int initial_size = 8;
    int array_size;
    int elements_size;
public:
    int getSize() const {
        return elements_size;
    }

private:
    bool wasIncreased;
    AVLTree<ServerAux>* table_array;
public:
    //ctor
    HashTable(): array_size(initial_size), elements_size(0), wasIncreased(false){
        table_array = new AVLTree<ServerAux>[initial_size];
    }
    //dtor
    ~HashTable(){ delete[] table_array;}
    void add(const ServerAux &serverAux){
        //hanlde error with enums
        if (serverAux.getID() <= 0) return;
        elements_size++;
        if ((((double) elements_size)/array_size) == 1) {
            enlargeSize();
            wasIncreased = true;
            array_size*=2;
        }
        table_array[serverAux.getID()%array_size].insert(serverAux);
    }

    void enlargeSize(){
        auto* new_arr = new AVLTree<ServerAux>[array_size*2];
        for (int i=0; i < array_size; i++){
            Array<ServerAux> tree_nums_array = table_array[i].getInOrder();
            for (int j = 0; j < (int)tree_nums_array.getSize(); j++){
                new_arr[tree_nums_array[j].getID()%(array_size*2)].insert(tree_nums_array[j]);
            }
        }
        delete[] table_array;
        table_array = new_arr;
    }

    void remove(const ServerAux &serverAux){
        //handle error with enums
        if (serverAux.getID() <= 0) return;
        elements_size--;
        if ((wasIncreased) && ((((double) elements_size)/array_size) == 0.25)) {
            decreaseSize();
            array_size/=2;
        }
        table_array[serverAux.getID()%array_size].remove(serverAux);
    }

    void decreaseSize(){
        auto* new_arr = new AVLTree<ServerAux>[array_size/2];
        for (int i=0; i < array_size; i++){
            Array<ServerAux> tree_nums_array = table_array[i].getInOrder();
            for (int j = 0; j < (int)tree_nums_array.getSize(); j++){
                new_arr[tree_nums_array[j].getID()%(array_size/2)].insert(tree_nums_array[j]);
            }
        }
        delete[] table_array;
        table_array = new_arr;
    }

    ServerAux find(ServerAux& given_sa) const{
        //std::random_device rd;
        //std::mt19937 engine(rd());
        //std::uniform_int_distribution<int> dist(0, array_size);
        //int cell = dist(engine);
        int cell = rand() % array_size;
        int remainder = cell;
        ServerAux sa_temp(0);
        do{
            try {
                sa_temp = table_array[cell%array_size].find(given_sa);
                return sa_temp;
            }
            catch (DataManagerExceptions::ObjectUnfound &e){
                cell++;
            }
        }
        while(cell%array_size != remainder);
        return sa_temp;
//
    }



};

#endif //DATACENTERSMANAGER2_HASHTABLE_H
