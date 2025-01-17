
#include <iostream>
//#include <assert.h>
//#include "ServersTraffTree.h"
#include "library2.h"
//#include "UF.h "
#include "DataCenter.h"

using namespace std;

int main() {

    int counter = 0;
    void **DS = new (void *);
    *DS = Init(100);
    assert(*DS != NULL);
    counter++;
    int sum = 0;
    cout << counter << endl;
    StatusType s = AddServer(*DS, 5, 5);
    s = SetTraffic(*DS, 5, 1);
    s = SumHighestTrafficServers(*DS, 5, 14, &sum);
    assert(s == SUCCESS && sum == 1);
    s = SetTraffic(*DS, 5, 10);
    s = SumHighestTrafficServers(*DS, 5, 0, &sum);
    assert(s == SUCCESS && sum == 0);
    s = SumHighestTrafficServers(*DS, 5, 1, &sum);
    assert(s == SUCCESS && sum == 10);
    s = SumHighestTrafficServers(*DS, 5, 14, &sum);
    assert(s == SUCCESS && sum == 10);
    s = AddServer(*DS, 5, 4);
    s = SetTraffic(*DS, 4, 1);
    s = SumHighestTrafficServers(*DS, 5, 14, &sum);
    assert(s == SUCCESS && sum == 11);
    s = SumHighestTrafficServers(*DS, 0, 14, &sum);
    assert(s == SUCCESS && sum == 11);
    s = SumHighestTrafficServers(*DS, 5, 2, &sum);
    assert(s == SUCCESS && sum == 11);
    s = SumHighestTrafficServers(*DS, 5, 1, &sum);
    assert(s == SUCCESS && sum == 10);
    s = SumHighestTrafficServers(*DS, 0, 1, &sum);
    assert(s == SUCCESS && sum == 10);

    s = AddServer(*DS, 5, 3);
    s = SetTraffic(*DS, 3, 12);
    s = SumHighestTrafficServers(*DS, 5, 14, &sum);
    assert(s == SUCCESS && sum == 23);
    s = SumHighestTrafficServers(*DS, 0, 14, &sum);
    assert(s == SUCCESS && sum == 23);
    s = SumHighestTrafficServers(*DS, 5, 2, &sum);
    assert(s == SUCCESS && sum == 22);
    s = SumHighestTrafficServers(*DS, 0, 2, &sum);
    assert(s == SUCCESS && sum == 22);
    s = SumHighestTrafficServers(*DS, 0, 1, &sum);
    assert(s == SUCCESS && sum == 12);
    s = SumHighestTrafficServers(*DS, 5, 1, &sum);
    assert(s == SUCCESS && sum == 12);
    s = AddServer(*DS, 4, 13);
    s = AddServer(*DS, 4, 23);
    s = AddServer(*DS, 4, 33);
    s = AddServer(*DS, 4, 43);
    s = SetTraffic(*DS, 13, 12);
    s = SetTraffic(*DS, 23, 12);
    s = SetTraffic(*DS, 33, 12);
    s = SetTraffic(*DS, 43, 12);
    s = MergeDataCenters(*DS, 4, 5);
    s = SumHighestTrafficServers(*DS, 5, 14, &sum);
    assert(s == SUCCESS && sum == 71);
    s = SumHighestTrafficServers(*DS, 0, 14, &sum);
    assert(s == SUCCESS && sum == 71);
    s = SumHighestTrafficServers(*DS, 4, 14, &sum);
    assert(s == SUCCESS && sum == 71);
    s = SumHighestTrafficServers(*DS, 0, 7, &sum);
    assert(s == SUCCESS && sum == 71);
    s = SumHighestTrafficServers(*DS, 4, 7, &sum);
    assert(s == SUCCESS && sum == 71);
    s = SumHighestTrafficServers(*DS, 5, 7, &sum);
    assert(s == SUCCESS && sum == 71);
    s = SumHighestTrafficServers(*DS, 0, 6, &sum);
    assert(s == SUCCESS && sum == 70);
    s = SumHighestTrafficServers(*DS, 4, 6, &sum);
    assert(s == SUCCESS && sum == 70);
    s = SumHighestTrafficServers(*DS, 5, 6, &sum);
    assert(s == SUCCESS && sum == 70);
    s = SumHighestTrafficServers(*DS, 0, 5, &sum);
    assert(s == SUCCESS && sum == 60);
    s = SumHighestTrafficServers(*DS, 4, 5, &sum);
    assert(s == SUCCESS && sum == 60);
    s = SumHighestTrafficServers(*DS, 5, 5, &sum);
    assert(s == SUCCESS && sum == 60);
    s = SumHighestTrafficServers(*DS, 0, 4, &sum);
    assert(s == SUCCESS && sum == 48);
    s = SumHighestTrafficServers(*DS, 4, 4, &sum);
    assert(s == SUCCESS && sum == 48);
    s = SumHighestTrafficServers(*DS, 5, 4, &sum);
    assert(s == SUCCESS && sum == 48);
    s = SumHighestTrafficServers(*DS, 0, 3, &sum);
    assert(s == SUCCESS && sum == 36);
    s = SumHighestTrafficServers(*DS, 4, 3, &sum);
    assert(s == SUCCESS && sum == 36);
    s = SumHighestTrafficServers(*DS, 5, 3, &sum);
    assert(s == SUCCESS && sum == 36);
    s = AddServer(*DS, 10, 101);
    s = AddServer(*DS, 10, 103);
    s = AddServer(*DS, 10, 201);
    s = AddServer(*DS, 10, 203);
    s = AddServer(*DS, 10, 301);
    s = AddServer(*DS, 10, 303);
    s = AddServer(*DS, 10, 113);
    s = AddServer(*DS, 10, 123);
    s = AddServer(*DS, 10, 133);
    s = SetTraffic(*DS, 101, 0);
    s = SetTraffic(*DS, 103, 5);
    s = SetTraffic(*DS, 201, 12);
    s = SetTraffic(*DS, 203, 0);
    s = SetTraffic(*DS, 301, 12);
    s = SetTraffic(*DS, 303, 12);
    s = SetTraffic(*DS, 113, 12);
    s = SetTraffic(*DS, 123, 12);
    s = SetTraffic(*DS, 133, 12);
    s = SumHighestTrafficServers(*DS, 0, 10, &sum);
    assert(s == SUCCESS && sum == 120);
    s = SumHighestTrafficServers(*DS, 10, 10, &sum);
    assert(s == SUCCESS && sum == 77);
    s = SumHighestTrafficServers(*DS, 0, 9, &sum);
    assert(s == SUCCESS && sum == 108);
    s = SumHighestTrafficServers(*DS, 10, 9, &sum);
    assert(s == SUCCESS && sum == 77);
    s = SumHighestTrafficServers(*DS, 0, 8, &sum);
    assert(s == SUCCESS && sum == 96);
    s = SumHighestTrafficServers(*DS, 10, 8, &sum);
    assert(s == SUCCESS && sum == 77);
    s = SumHighestTrafficServers(*DS, 0, 7, &sum);
    assert(s == SUCCESS && sum == 84);
    s = SumHighestTrafficServers(*DS, 10, 7, &sum);
    assert(s == SUCCESS && sum == 77);
    s = SumHighestTrafficServers(*DS, 0, 6, &sum);
    assert(s == SUCCESS && sum == 72);
    s = SumHighestTrafficServers(*DS, 10, 6, &sum);
    assert(s == SUCCESS && sum == 72);
    s = SumHighestTrafficServers(*DS, 0, 5, &sum);
    assert(s == SUCCESS && sum == 60);
    s = SumHighestTrafficServers(*DS, 10, 5, &sum);
    assert(s == SUCCESS && sum == 60);
    s = SumHighestTrafficServers(*DS, 0, 4, &sum);
    assert(s == SUCCESS && sum == 48);
    s = SumHighestTrafficServers(*DS, 10, 4, &sum);
    assert(s == SUCCESS && sum == 48);
    s = SumHighestTrafficServers(*DS, 0, 3, &sum);
    assert(s == SUCCESS && sum == 36);
    s = SumHighestTrafficServers(*DS, 10, 3, &sum);
    assert(s == SUCCESS && sum == 36);
    s = SumHighestTrafficServers(*DS, 0, 2, &sum);
    assert(s == SUCCESS && sum == 24);
    s = SumHighestTrafficServers(*DS, 10, 2, &sum);
    assert(s == SUCCESS && sum == 24);
    s = MergeDataCenters(*DS, 4, 10);
    s = SumHighestTrafficServers(*DS, 0, 16, &sum);
    assert(s == SUCCESS && sum == 148);
    s = SumHighestTrafficServers(*DS, 5, 16, &sum);
    assert(s == SUCCESS && sum == 148);
    s = SumHighestTrafficServers(*DS, 10, 16, &sum);
    assert(s == SUCCESS && sum == 148);
    s = SumHighestTrafficServers(*DS, 4, 16, &sum);
    assert(s == SUCCESS && sum == 148);
    s = SumHighestTrafficServers(*DS, 0, 15, &sum);
    assert(s == SUCCESS && sum == 148);
    s = SumHighestTrafficServers(*DS, 10, 15, &sum);
    assert(s == SUCCESS && sum == 148);
    s = SumHighestTrafficServers(*DS, 4, 15, &sum);
    assert(s == SUCCESS && sum == 148);
    s = SumHighestTrafficServers(*DS, 5, 15, &sum);
    assert(s == SUCCESS && sum == 148);
    s = SumHighestTrafficServers(*DS, 0, 14, &sum);
    assert(s == SUCCESS && sum == 148);
    s = SumHighestTrafficServers(*DS, 10, 14, &sum);
    assert(s == SUCCESS && sum == 148);
    s = SumHighestTrafficServers(*DS, 5, 14, &sum);
    assert(s == SUCCESS && sum == 148);
    s = SumHighestTrafficServers(*DS, 4, 14, &sum);
    assert(s == SUCCESS && sum == 148);
    s = SumHighestTrafficServers(*DS, 0, 13, &sum);
    assert(s == SUCCESS && sum == 147);
    s = SumHighestTrafficServers(*DS, 10, 13, &sum);
    assert(s == SUCCESS && sum == 147);
    s = SumHighestTrafficServers(*DS, 5, 13, &sum);
    assert(s == SUCCESS && sum == 147);
    s = SumHighestTrafficServers(*DS, 4, 13, &sum);
    assert(s == SUCCESS && sum == 147);
    s = SumHighestTrafficServers(*DS, 0, 12, &sum);
    assert(s == SUCCESS && sum == 142);
    s = SumHighestTrafficServers(*DS, 10, 12, &sum);
    assert(s == SUCCESS && sum == 142);
    s = SumHighestTrafficServers(*DS, 5, 12, &sum);
    assert(s == SUCCESS && sum == 142);
    s = SumHighestTrafficServers(*DS, 4, 12, &sum);
    assert(s == SUCCESS && sum == 142);

    for (int i = 0; i < 20; i++) {
        s = AddServer(*DS, 20, 400 + i);
        s = SetTraffic(*DS, 400 + i, i + 1);
        s = AddServer(*DS, 30, 500 + i);
        s = SetTraffic(*DS, 500 + i, i + 1);
        s = AddServer(*DS, 40, 600 + i);
        s = SetTraffic(*DS, 600 + i, i + 1);
        s = AddServer(*DS, 50, 700 + i);
        s = SetTraffic(*DS, 700 + i, i + 1);
    }
    s = MergeDataCenters(*DS, 20, 30);
    s = MergeDataCenters(*DS, 40, 50);
    s = SumHighestTrafficServers(*DS, 30, 10, &sum);
    assert(s == SUCCESS && sum == 180);
    s = SumHighestTrafficServers(*DS, 20, 1, &sum);
    assert(s == SUCCESS && sum == 20);
    s = SumHighestTrafficServers(*DS, 30, 5, &sum);
    assert(s == SUCCESS && sum == 96);
    s = SumHighestTrafficServers(*DS, 20, 2, &sum);
    assert(s == SUCCESS && sum == 40);
    s = SumHighestTrafficServers(*DS, 30, 3, &sum);
    assert(s == SUCCESS && sum == 59);
    s = SumHighestTrafficServers(*DS, 20, 4, &sum);
    assert(s == SUCCESS && sum == 78);
    s = SumHighestTrafficServers(*DS, 30, 5, &sum);
    assert(s == SUCCESS && sum == 96);
    s = SumHighestTrafficServers(*DS, 20, 120, &sum);
    assert(s == SUCCESS && sum == 420);
    s = SumHighestTrafficServers(*DS, 30, 10, &sum);
    assert(s == SUCCESS && sum == 180);
    s = SumHighestTrafficServers(*DS, 20, 6, &sum);
    assert(s == SUCCESS && sum == 114);
    s = SumHighestTrafficServers(*DS, 30, 7, &sum);
    assert(s == SUCCESS && sum == 131);
    s = SumHighestTrafficServers(*DS, 20, 8, &sum);
    assert(s == SUCCESS && sum == 148);


    for (int i = 0; i < 20; i++) {
        s = RemoveServer(*DS, 600 + i);
        s = RemoveServer(*DS, 700 + i);
    }
    s = SumHighestTrafficServers(*DS, 40, 10, &sum);
    assert(s == SUCCESS && sum == 0);
    for (int i = 1; i <= 100; i++) {
        s = AddServer(*DS, 60, 60 * i);
        s = SetTraffic(*DS, 60 * i, i);
    }
    s = SumHighestTrafficServers(*DS, 60, 100, &sum);
    assert(s == SUCCESS && sum == 5050);
    for (int i = 1; i <= 50; i++) {
        s = RemoveServer(*DS, 60 * i);

    }
    s = SumHighestTrafficServers(*DS, 60, 100, &sum);
    assert(s == SUCCESS && sum == 3775);
    for (int i = 1; i <= 500; i++) {
        s = AddServer(*DS, 70, i);
        s = SetTraffic(*DS, i, i);
    }
    s = RemoveServer(*DS, 60);
    Quit(DS);


    cout << "*******************************************************" << "\n";
    cout << "*******************************************************" << "\n";
    cout << "YOU HAVE PASSED THE TEST ^___^" << "\n" << "GOOD LUCK IN THE FINAL EXAM";
    cout << "\n" << "*******************************************************" << "\n";
    cout << "*******************************************************" << "\n";



//
//    void** DS=new (void*);
//    *DS=Init(10);
//    assert(*DS!=NULL);
//    StatusType s=AddServer(*DS,11,10);
//    assert(s==INVALID_INPUT);
//    s=AddServer(*DS,0,10);
//    assert(s==INVALID_INPUT);
//    s=AddServer(*DS,-1,10);
//    assert(s==INVALID_INPUT);
//    s=AddServer(*DS,5,0);
//    assert(s==INVALID_INPUT);
//    s=AddServer(*DS,5,-44);
//    assert(s==INVALID_INPUT);
//    s=AddServer(nullptr,5,-44);
//    assert(s==INVALID_INPUT);
//    s=AddServer(*DS,5,1);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,5,1);
//    assert(s==FAILURE);
//    s=AddServer(*DS,1,1);
//    assert(s==FAILURE);
//    s=AddServer(*DS,1,2);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,1,3);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,2,3);
//    assert(s==FAILURE);
//    s=AddServer(*DS,2,4);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,10,5);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,10,6);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,9,6);
//    assert(s==FAILURE);
//    s=AddServer(*DS,9,7);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,9,8);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,8,9);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,8,10);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,8,11);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,7,12);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,7,13);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,6,14);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,5,15);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,5,16);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,4,17);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,4,18);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,3,19);
//    assert(s==SUCCESS);
//    s=AddServer(*DS,3,20);
//    assert(s==SUCCESS);
//    s=RemoveServer(*DS,4);
//    assert(s==SUCCESS);
//    s=RemoveServer(*DS,4);
//    assert(s==FAILURE);
//    s=RemoveServer(*DS,10);
//    assert(s==SUCCESS);
//    s=RemoveServer(*DS,21);
//    assert(s==FAILURE);
//    s=RemoveServer(*DS,0);
//    assert(s==INVALID_INPUT);
//    s=RemoveServer(nullptr,9);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(nullptr,3,3);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,0,3);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,-1,3);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,21,3);
//    assert(s==FAILURE);
//    s=SetTraffic(*DS,4,3);
//    assert(s==FAILURE);
//    s=SetTraffic(*DS,10,3);
//    assert(s==FAILURE);
//    s=SetTraffic(*DS,1,-1);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,5,-1);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,10,-1);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,9,-1);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,4,-1);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,14,-1);
//    assert(s==INVALID_INPUT);
//    s=SetTraffic(*DS,14,5);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,20,11);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,3,11);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,2,3);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,6,4);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,13,7);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,18,25);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,16,12);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,12,12);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,7,5);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,8,5);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,8,10);
//    assert(s==SUCCESS);
//    int sum=0;
//    s=SumHighestTrafficServers(nullptr,5,1,&sum);
//    assert(s==INVALID_INPUT);
//    s=SumHighestTrafficServers(*DS,5,-1,&sum);
//    assert(s==INVALID_INPUT);
//    s=SumHighestTrafficServers(*DS,21,1,&sum);
//    assert(s==INVALID_INPUT);
//    s=SumHighestTrafficServers(*DS,-1,1,&sum);
//    assert(s==INVALID_INPUT);
//    s=SumHighestTrafficServers(*DS,0,1,&sum);
//    assert(s==SUCCESS && sum==25);
//    s=SumHighestTrafficServers(*DS,0,3,&sum);
//    assert(s==SUCCESS && sum==49);
//    s=SumHighestTrafficServers(*DS,0,5,&sum);
//    assert(s==SUCCESS && sum==71);
//    s=SetTraffic(*DS,3,2);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,0,5,&sum);
//    assert(s==SUCCESS && sum==70);
//    s=SetTraffic(*DS,9,21);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,0,5,&sum);
//    assert(s==SUCCESS && sum==81);
//    s=SumHighestTrafficServers(*DS,5,3,&sum);
//    assert(s==SUCCESS && sum==12);
//    s=SetTraffic(*DS,15,2);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,5,3,&sum);
//    assert(s==SUCCESS && sum==14);
//    s=SetTraffic(*DS,1,1);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,5,3,&sum);
//    assert(s==SUCCESS && sum==15);
//    s=MergeDataCenters(nullptr,5,2);
//    assert(s==INVALID_INPUT);
//    s=MergeDataCenters(*DS,4,0);
//    assert(s==INVALID_INPUT);
//    s=MergeDataCenters(*DS,0,4);
//    assert(s==INVALID_INPUT);
//    s=MergeDataCenters(*DS,21,4);
//    assert(s==INVALID_INPUT);
//    s=MergeDataCenters(*DS,4,23);
//    assert(s==INVALID_INPUT);
//    s=MergeDataCenters(*DS,4,5);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,4,3,&sum);
//    assert(s==SUCCESS && sum==39);
//    s=SumHighestTrafficServers(*DS,5,3,&sum);
//    assert(s==SUCCESS && sum==39);
//    s=SetTraffic(*DS,16,8);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,5,3,&sum);
//    assert(s==SUCCESS && sum==35);
//    s=SumHighestTrafficServers(*DS,5,1,&sum);
//    assert(s==SUCCESS && sum==25);
//    s=SumHighestTrafficServers(*DS,5,2,&sum);
//    assert(s==SUCCESS && sum==33);
//    s=SumHighestTrafficServers(*DS,5,4,&sum);
//    assert(s==SUCCESS && sum==36);
//    s=SumHighestTrafficServers(*DS,5,5,&sum);
//    assert(s==SUCCESS && sum==36);
//    s=SumHighestTrafficServers(*DS,4,3,&sum);
//    assert(s==SUCCESS && sum==35);
//    s=SumHighestTrafficServers(*DS,4,1,&sum);
//    assert(s==SUCCESS && sum==25);
//    s=SumHighestTrafficServers(*DS,4,2,&sum);
//    assert(s==SUCCESS && sum==33);
//    s=SumHighestTrafficServers(*DS,4,4,&sum);
//    assert(s==SUCCESS && sum==36);
//    s=SumHighestTrafficServers(*DS,4,5,&sum);
//    assert(s==SUCCESS && sum==36);
//    s=AddServer(*DS,4,10);
//    assert(s==SUCCESS );
//    s=SetTraffic(*DS,10,30);
//    assert(s==SUCCESS );
//    s=SumHighestTrafficServers(*DS,4,2,&sum);
//    assert(s==SUCCESS && sum==55);
//    s=SumHighestTrafficServers(*DS,5,2,&sum);
//    assert(s==SUCCESS && sum==55);
//    s=MergeDataCenters(*DS,4,9);
//    assert(s==SUCCESS);
//    s=SetTraffic(*DS,8,60);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,4,1,&sum);
//    assert(s==SUCCESS && sum==60);
//    s=SumHighestTrafficServers(*DS,5,1,&sum);
//    assert(s==SUCCESS && sum==60);
//    s=SumHighestTrafficServers(*DS,9,1,&sum);
//    assert(s==SUCCESS && sum==60);
//    s=SumHighestTrafficServers(*DS,4,2,&sum);
//    assert(s==SUCCESS && sum==90);
//    s=SumHighestTrafficServers(*DS,5,2,&sum);
//    assert(s==SUCCESS && sum==90);
//    s=SumHighestTrafficServers(*DS,9,2,&sum);
//    assert(s==SUCCESS && sum==90);
//    s=SumHighestTrafficServers(*DS,5,4,&sum);
//    assert(s==SUCCESS && sum==123);
//    s=SumHighestTrafficServers(*DS,0,1,&sum);
//    assert(s==SUCCESS && sum==60);
//    s=SumHighestTrafficServers(*DS,0,3,&sum);
//    assert(s==SUCCESS && sum==115);
//    s=RemoveServer(*DS,8);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,5,1,&sum);
//    assert(s==SUCCESS && sum==30);
//    s=SetTraffic(*DS,7,100);
//    assert(s==SUCCESS);
//    s=SumHighestTrafficServers(*DS,0,1,&sum);
//    assert(s==SUCCESS && sum==100);
//    s=SumHighestTrafficServers(*DS,5,1,&sum);
//    assert(s==SUCCESS && sum==100);
//    s=SumHighestTrafficServers(*DS,5,2,&sum);
//    assert(s==SUCCESS && sum==130);
//    s=SumHighestTrafficServers(*DS,9,2,&sum);
//    assert(s==SUCCESS && sum==130);
//    s=SumHighestTrafficServers(*DS,4,2,&sum);
//    assert(s==SUCCESS && sum==130);
//    s=SumHighestTrafficServers(*DS,5,6,&sum);
//    assert(s==SUCCESS && sum==166);
//    s=SumHighestTrafficServers(*DS,4,6,&sum);
//    assert(s==SUCCESS && sum==166);
//    s=SumHighestTrafficServers(*DS,9,6,&sum);
//    assert(s==SUCCESS && sum==166);
//    Quit(DS);
//    delete DS;
//    cout<<"*******************************************************"<<"\n";
//    cout<<"*******************************************************"<<"\n";
//    cout<<"YOU HAVE PASSED THE TEST ^___^"<<"\n"<<"GOOD LUCK IN THE FINAL EXAM";
//    cout<<"\n"<<"*******************************************************"<<"\n";
//    cout<<"*******************************************************"<<"\n";
}

