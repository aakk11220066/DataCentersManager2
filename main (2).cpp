#include "library2.h"
#include <assert.h>
#include <iostream>

using std::cout;

int main() {
    void **DS = new (void *);
    *DS = Init(10);
    assert(*DS != NULL);
    StatusType s = AddServer(*DS, 11, 10);
    assert(s == INVALID_INPUT);
    s = AddServer(*DS, 0, 10);
    assert(s == INVALID_INPUT);
    s = AddServer(*DS, -1, 10);
    assert(s == INVALID_INPUT);
    s = AddServer(*DS, 5, 0);
    assert(s == INVALID_INPUT);
    s = AddServer(*DS, 5, -44);
    assert(s == INVALID_INPUT);
    s = AddServer(nullptr, 5, -44);
    assert(s == INVALID_INPUT);
    s = AddServer(*DS, 5, 1);
    assert(s == SUCCESS);
    s = AddServer(*DS, 5, 1);
    assert(s == FAILURE);
    s = AddServer(*DS, 1, 1);
    assert(s == FAILURE);
    s = AddServer(*DS, 1, 2);
    assert(s == SUCCESS);
    s = AddServer(*DS, 1, 3);
    assert(s == SUCCESS);
    s = AddServer(*DS, 2, 3);
    assert(s == FAILURE);
    s = AddServer(*DS, 2, 4);
    assert(s == SUCCESS);
    s = AddServer(*DS, 10, 5);
    assert(s == SUCCESS);
    s = AddServer(*DS, 10, 6);
    assert(s == SUCCESS);
    s = AddServer(*DS, 9, 6);
    assert(s == FAILURE);
    s = AddServer(*DS, 9, 7);
    assert(s == SUCCESS);
    s = AddServer(*DS, 9, 8);
    assert(s == SUCCESS);
    s = AddServer(*DS, 8, 9);
    assert(s == SUCCESS);
    s = AddServer(*DS, 8, 10);
    assert(s == SUCCESS);
    s = AddServer(*DS, 8, 11);
    assert(s == SUCCESS);
    s = AddServer(*DS, 7, 12);
    assert(s == SUCCESS);
    s = AddServer(*DS, 7, 13);
    assert(s == SUCCESS);
    s = AddServer(*DS, 6, 14);
    assert(s == SUCCESS);
    s = AddServer(*DS, 5, 15);
    assert(s == SUCCESS);
    s = AddServer(*DS, 5, 16);
    assert(s == SUCCESS);
    s = AddServer(*DS, 4, 17);
    assert(s == SUCCESS);
    s = AddServer(*DS, 4, 18);
    assert(s == SUCCESS);
    s = AddServer(*DS, 3, 19);
    assert(s == SUCCESS);
    s = AddServer(*DS, 3, 20);
    assert(s == SUCCESS);
    s = RemoveServer(*DS, 4);
    assert(s == SUCCESS);
    s = RemoveServer(*DS, 4);
    assert(s == FAILURE);
    s = RemoveServer(*DS, 10);
    assert(s == SUCCESS);
    s = RemoveServer(*DS, 21);
    assert(s == FAILURE);
    s = RemoveServer(*DS, 0);
    assert(s == INVALID_INPUT);
    s = RemoveServer(nullptr, 9);
    assert(s == INVALID_INPUT);
    s = SetTraffic(nullptr, 3, 3);
    assert(s == INVALID_INPUT);
    s = SetTraffic(*DS, 0, 3);
    assert(s == INVALID_INPUT);
    s = SetTraffic(*DS, -1, 3);
    assert(s == INVALID_INPUT);
    s = SetTraffic(*DS, 21, 3);
    assert(s == FAILURE);
    s = SetTraffic(*DS, 4, 3);
    assert(s == FAILURE);
    s = SetTraffic(*DS, 10, 3);
    assert(s == FAILURE);
    s = SetTraffic(*DS, 1, -1);
    assert(s == INVALID_INPUT);
    s = SetTraffic(*DS, 5, -1);
    assert(s == INVALID_INPUT);
    s = SetTraffic(*DS, 10, -1);
    assert(s == INVALID_INPUT);
    s = SetTraffic(*DS, 9, -1);
    assert(s == INVALID_INPUT);
    s = SetTraffic(*DS, 4, -1);
    assert(s == INVALID_INPUT);
    s = SetTraffic(*DS, 14, -1);
    assert(s == INVALID_INPUT);
    s = SetTraffic(*DS, 14, 5);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 20, 11);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 3, 11);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 2, 3);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 6, 4);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 13, 7);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 18, 25);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 16, 12);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 12, 12);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 7, 5);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 8, 5);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 8, 10);
    assert(s == SUCCESS);
    int sum = 0;
    s = SumHighestTrafficServers(nullptr, 5, 1, &sum);
    assert(s == INVALID_INPUT);
    s = SumHighestTrafficServers(*DS, 5, -1, &sum);
    assert(s == INVALID_INPUT);
    s = SumHighestTrafficServers(*DS, 21, 1, &sum);
    assert(s == INVALID_INPUT);
    s = SumHighestTrafficServers(*DS, -1, 1, &sum);
    assert(s == INVALID_INPUT);
    s = SumHighestTrafficServers(*DS, 0, 1, &sum);
    assert(s == SUCCESS && sum == 25);
    s = SumHighestTrafficServers(*DS, 0, 3, &sum);
    assert(s == SUCCESS && sum == 49);
    s = SumHighestTrafficServers(*DS, 0, 5, &sum);
    assert(s == SUCCESS && sum == 71);
    s = SetTraffic(*DS, 3, 2);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 0, 5, &sum);
    assert(s == SUCCESS && sum == 70);
    s = SetTraffic(*DS, 9, 21);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 0, 5, &sum);
    assert(s == SUCCESS && sum == 81);
    s = SumHighestTrafficServers(*DS, 5, 3, &sum);
    assert(s == SUCCESS && sum == 12);
    s = SetTraffic(*DS, 15, 2);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 5, 3, &sum);
    assert(s == SUCCESS && sum == 14);
    s = SetTraffic(*DS, 1, 1);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 5, 3, &sum);
    assert(s == SUCCESS && sum == 15);
    s = MergeDataCenters(nullptr, 5, 2);
    assert(s == INVALID_INPUT);
    s = MergeDataCenters(*DS, 4, 0);
    assert(s == INVALID_INPUT);
    s = MergeDataCenters(*DS, 0, 4);
    assert(s == INVALID_INPUT);
    s = MergeDataCenters(*DS, 21, 4);
    assert(s == INVALID_INPUT);
    s = MergeDataCenters(*DS, 4, 23);
    assert(s == INVALID_INPUT);
    s = MergeDataCenters(*DS, 4, 5);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 4, 3, &sum);
    assert(s == SUCCESS && sum == 39);
    s = SumHighestTrafficServers(*DS, 5, 3, &sum);
    assert(s == SUCCESS && sum == 39);
    s = SetTraffic(*DS, 16, 8);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 5, 3, &sum);
    assert(s == SUCCESS && sum == 35);
    s = SumHighestTrafficServers(*DS, 5, 1, &sum);
    assert(s == SUCCESS && sum == 25);
    s = SumHighestTrafficServers(*DS, 5, 2, &sum);
    assert(s == SUCCESS && sum == 33);
    s = SumHighestTrafficServers(*DS, 5, 4, &sum);
    assert(s == SUCCESS && sum == 36);
    s = SumHighestTrafficServers(*DS, 5, 5, &sum);
    assert(s == SUCCESS && sum == 36);
    s = SumHighestTrafficServers(*DS, 4, 3, &sum);
    assert(s == SUCCESS && sum == 35);
    s = SumHighestTrafficServers(*DS, 4, 1, &sum);
    assert(s == SUCCESS && sum == 25);
    s = SumHighestTrafficServers(*DS, 4, 2, &sum);
    assert(s == SUCCESS && sum == 33);
    s = SumHighestTrafficServers(*DS, 4, 4, &sum);
    assert(s == SUCCESS && sum == 36);
    s = SumHighestTrafficServers(*DS, 4, 5, &sum);
    assert(s == SUCCESS && sum == 36);
    s = AddServer(*DS, 4, 10);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 10, 30);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 4, 2, &sum);
    assert(s == SUCCESS && sum == 55);
    s = SumHighestTrafficServers(*DS, 5, 2, &sum);
    assert(s == SUCCESS && sum == 55);
    s = MergeDataCenters(*DS, 4, 9);
    assert(s == SUCCESS);
    s = SetTraffic(*DS, 8, 60);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 4, 1, &sum);
    assert(s == SUCCESS && sum == 60);
    s = SumHighestTrafficServers(*DS, 5, 1, &sum);
    assert(s == SUCCESS && sum == 60);
    s = SumHighestTrafficServers(*DS, 9, 1, &sum);
    assert(s == SUCCESS && sum == 60);
    s = SumHighestTrafficServers(*DS, 4, 2, &sum);
    assert(s == SUCCESS && sum == 90);
    s = SumHighestTrafficServers(*DS, 5, 2, &sum);
    assert(s == SUCCESS && sum == 90);
    s = SumHighestTrafficServers(*DS, 9, 2, &sum);
    assert(s == SUCCESS && sum == 90);
    s = SumHighestTrafficServers(*DS, 5, 4, &sum);
    assert(s == SUCCESS && sum == 123);
    s = SumHighestTrafficServers(*DS, 0, 1, &sum);
    assert(s == SUCCESS && sum == 60);
    s = SumHighestTrafficServers(*DS, 0, 3, &sum);
    assert(s == SUCCESS && sum == 115);
    s = RemoveServer(*DS, 8);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 5, 1, &sum);
    assert(s == SUCCESS && sum == 30);
    s = SetTraffic(*DS, 7, 100);
    assert(s == SUCCESS);
    s = SumHighestTrafficServers(*DS, 0, 1, &sum);
    assert(s == SUCCESS && sum == 100);
    s = SumHighestTrafficServers(*DS, 5, 1, &sum);
    assert(s == SUCCESS && sum == 100);
    s = SumHighestTrafficServers(*DS, 5, 2, &sum);
    assert(s == SUCCESS && sum == 130);
    s = SumHighestTrafficServers(*DS, 9, 2, &sum);
    assert(s == SUCCESS && sum == 130);
    s = SumHighestTrafficServers(*DS, 4, 2, &sum);
    assert(s == SUCCESS && sum == 130);
    s = SumHighestTrafficServers(*DS, 5, 6, &sum);
    assert(s == SUCCESS && sum == 166);
    s = SumHighestTrafficServers(*DS, 4, 6, &sum);
    assert(s == SUCCESS && sum == 166);
    s = SumHighestTrafficServers(*DS, 9, 6, &sum);
    assert(s == SUCCESS && sum == 166);
    Quit(DS);
    delete DS;
    cout << "*******************************************************" << "\n";
    cout << "*******************************************************" << "\n";
    cout << "YOU HAVE PASSED THE TEST ^___^" << "\n" << "GOOD LUCK IN THE FINAL EXAM";
    cout << "\n" << "*******************************************************" << "\n";
    cout << "*******************************************************" << "\n";
}