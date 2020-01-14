
#include "Data Structures/AVLTree/AVLTree.h"
#include "DataCenterManager.h"
#include "library2.h"

using std::cout;
using std::endl;

int main() {
    /*
    //AVLTree sum, rank test (passed)
    AVLTree<int> tree; //instantiation success
    for (int i=1; i<10; ++i) tree.insert(i);
    std::cout << "Searching for 6, found " << tree.find(6) << std::endl;
    std::cout << "Relative index of 6 is " << tree.getRelativeIndex(6) << " and should be 5." << std::endl;
    std::cout << "Sum of numbers up to 6 is " << tree.getPartialSum(6) << " and should be 21." << std::endl;

    //set test
    Set *sets = new Set[10];
    Server *servers = new Server[30];
    for (int i = 0; i < 10; ++i) sets[i] = Set(); //init
    for (int i = 0; i < 30; ++i) servers[i] = Server(); //init
    cout << "Passed constructor tests" << endl;

    for (int i = 0; i < 30; ++i) sets[i % 10].insert(servers[i].link);
    Set set3 = Set::find(servers[3].link);
    Set set23 = Set::find(servers[23].link);
    assert(set3 == set23);
    cout << "Passed insertion, find, and equality tests." << endl;

    Set::setsUnion(servers[0].link, servers[1].link);
    assert(Set::find(servers[10].link) == Set::find(servers[21].link));
    assert(!(Set::find(servers[10].link) == Set::find(servers[22].link)));
    cout << "Passed union test." << endl;

    for (int i = 1; i < 10; ++i) { //unite all first 10 servers
        Set::setsUnion(servers[i].link, servers[i + 1].link);
    }
    for (int i = 0; i < 30; ++i) { //ensure all servers are connected
        for (int j = 0; j < 30; ++j) {
            assert(Set::find(servers[i].link) == Set::find(servers[j].link));
        }
    }
    for (int i = 1; i < 30; ++i) {
        assert(servers[i].link.parent == &(servers[0].link)); //ensure find shortened all paths correctly
    }
    cout << "Passed union proper connections test." << endl;
    delete[] sets;
    delete[] servers;
     */

    /*
    //AVLTree Merge test
    //init
    const unsigned int NUMTREES = 3, MAXVAL = 10;
    AVLTree<int> *trees = new AVLTree<int>[NUMTREES];
    for (int i = 0; i < NUMTREES; ++i) trees[i] = AVLTree<int>();
    for (int j = 0; j < NUMTREES; ++j) {
        for (int i = 0; i < MAXVAL; ++i) trees[j].insert(NUMTREES * i + j);
    }
    cout << "Prepared trees with mod " << NUMTREES << " values going up to " << MAXVAL << ".  Trees contain:" << endl;
    for (int j = 0; j < NUMTREES; ++j) {
        cout << "tree number " << j << ": ";
        for (int i = 0; i < trees[j].getInOrder().getSize(); ++i) {
            cout << trees[j].getInOrder()[i] << ", ";
        }
        cout << endl;
    }

    trees[0] = trees[0].merge(trees[1]);

    cout << "Successfully merged 3i and 3i+1 trees, inorder printout of resultant tree:" << endl;
    auto inorder = trees[1].getInOrder();
    for (int i = 0; i < inorder.getSize(); ++i) {
        cout << inorder[i] << ", ";
    }
    cout << "." << endl;

    //operator[] test
    unsigned int relativeIndexOfEleven = trees[2].getRelativeIndex(11);
    cout << "The relative index of 11 in trees[2] is " << relativeIndexOfEleven << "." << endl;
    cout << "The element with relative index " << relativeIndexOfEleven << " is " << trees[2][relativeIndexOfEleven]
         << " and should be 11." << endl;

    delete[] trees;
    */

    /*DataCenter dc1(1);
    DataCenter dc2(2);
    dc1.AddServer(6);
    dc1.SetTraffic(Server(6, 0, 1), 6);
    dc1.AddServer(7);
    dc1.SetTraffic(Server(7, 0, 1), 7);
    dc1.AddServer(8);
    dc1.SetTraffic(Server(8, 0, 1), 8);
    dc2.AddServer(9);
    dc2.SetTraffic(Server(9, 0, 2), 9);
    dc1.merge(dc2);
    int tr_res;
    dc1.SumHighestTrafficServers(1, &tr_res);
    printf("tr_res is %d\n", tr_res);
    cout << "merge followed by sumHighestTrafficServers test complete." << endl;*/
    //------DataCenterManager initialization test---------
    //DataCenterManager manager(20);

    /*
    DataCenterManager dcm(5);
    int res = dcm.AddServer(2,4);
    printf("it is %d\n", res);
    res = dcm.AddServer(3,4);
    printf("it is %d\n", res);
    res = dcm.RemoveServer(3);
    printf("result is %d\n", res);
    res = dcm.SetTraffic(4,7);
    printf("result now is %d\n", res);
    res = dcm.RemoveServer(4);
    printf("res please be %d\n", res);
    //UnionFind uf(5);
    //int res1 = uf.find(0);
    //printf("res1 is %d\n", res1);
    //DataCenterManager dcm(5);
    //int res = dcm.AddServer(2,4);
    */

    //int a =5;

    //-----main2 tests-----
    auto ds = Init(10);
    AddServer(ds, 1, 1);
    AddServer(ds, 2, 1);
    AddServer(ds, 2, 2);
    SetTraffic(ds, 1, 10);
    SetTraffic(ds, 2, 20);
    int *output = new int;
    SumHighestTrafficServers(ds, 1, 2, output);
    cout << "SumHighestTrafficServers returned " << *output << endl;
    SumHighestTrafficServers(ds, 2, 2, output);
    cout << "SumHighestTrafficServers returned " << *output << endl;
    SumHighestTrafficServers(ds, 0, 2, output);
    cout << "SumHighestTrafficServers returned " << *output << endl;
    MergeDataCenters(ds, 1, 2);
    SumHighestTrafficServers(ds, 1, 2, output);
    cout << "SumHighestTrafficServers returned " << *output << endl;
    SumHighestTrafficServers(ds, 2, 2, output);
    cout << "SumHighestTrafficServers returned " << *output << endl;
    SumHighestTrafficServers(ds, 0, 2, output);
    cout << "SumHighestTrafficServers returned " << *output << endl;
    Quit(&ds);

    delete (output);
}