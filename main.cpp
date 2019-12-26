#include <iostream>
#include "Data Structures/AVLTree/AVLTree.h"
#include "Data Structures/Set.h"
#include "Server.h"
#include <assert.h>

using std::cout;
using std::endl;
int main() {
    //AVLTree sum, rank test (passed)
    AVLTree<int> tree; //instantiation success
    for (int i=1; i<10; ++i) tree.insert(i);
    std::cout << "Searching for 6, found " << tree.find(6) << std::endl;
    std::cout << "Relative index of 6 is " << tree.getRelativeIndex(6) << " and should be 5." << std::endl;
    std::cout << "Sum of numbers up to 6 is " << tree.getPartialSum(6) << " and should be 21." << std::endl;

    //set test
    Set<Server> *sets = new Set<Server>[10];
    Server *servers = new Server[30];
    for (int i = 0; i < 10; ++i) sets[i] = Set<Server>(); //init
    for (int i = 0; i < 30; ++i) servers[i] = Server(); //init
    cout << "Passed constructor tests" << endl;

    for (int i = 0; i < 30; ++i) sets[i % 10].insert(servers[i].link);
    Set<Server> set3 = Set<Server>::find(servers[3].link);
    Set<Server> set23 = Set<Server>::find(servers[23].link);
    assert(set3 == set23);
    cout << "Passed insertion, find, and equality tests." << endl;

    Set<Server>::setsUnion(servers[0].link, servers[1].link);
    assert(Set<Server>::find(servers[10].link) == Set<Server>::find(servers[21].link));
    assert(!(Set<Server>::find(servers[10].link) == Set<Server>::find(servers[22].link)));
    cout << "Passed union test." << endl;

    for (int i = 1; i < 10; ++i) { //unite all first 10 servers
        Set<Server>::setsUnion(servers[i].link, servers[i + 1].link);
    }
    for (int i = 0; i < 30; ++i) { //ensure all servers are connected
        for (int j = 0; j < 30; ++j) {
            assert(Set<Server>::find(servers[i].link) == Set<Server>::find(servers[j].link));
        }
    }
    for (int i = 1; i < 30; ++i) {
        assert(servers[i].link.parent == &(servers[0].link)); //ensure find shortened all paths correctly
    }
    cout << "Passed union proper connections test." << endl;
}