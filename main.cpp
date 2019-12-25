#include <iostream>
#include "Data Structures/AVLTree/AVLTree.h"

int main() {
    AVLTree<int> tree; //instantiation success
    for (int i=1; i<10; ++i) tree.insert(i);
    std::cout << "Searching for 6, found " << tree.find(6) << std::endl;
    std::cout << "Relative index of 6 is " << tree.getRelativeIndex(6) << " and should be 5." << std::endl;
    std::cout << "Sum of numbers up to 6 is " << tree.getPartialSum(6) << " and should be 21." << std::endl;
    return 0;
}