cmake_minimum_required(VERSION 3.13)
project(DataCentersManager2)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataCentersManager2 main.cpp "Data Structures/AVLTree/AVLTree.h" "Data Structures/Array.h" "Data Structures/AVLTree/BinarySearchTree.h" "Data Structures/AVLTree/BinaryTree.h" "Data Structures/Array.h" "Data Structures/linkedList.h" Server.h DataCenter.h DataCenterManager.h "Data Structures/UnionFind.h" "UnionFind/Set.h" library2.cpp library2.h)
