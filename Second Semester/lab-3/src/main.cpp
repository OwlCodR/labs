#include <iostream>

#include "BinarySearchTree/BinarySearchTree.h"
#include "BinarySearchTree/BinarySearchTree.cpp"

using namespace std;

int main() {
    BinarySearchTree<int> tree;

    // tree.add(4);
    // tree.add(2);
    // tree.add(3);
    // tree.add(1);
    // tree.add(5);
    // // tree.add(6);
    // cout << tree.toString("{}()[]", "KLP") << endl;
    tree.fromString("{4}({2}(1)[3])[5]", "{}()[]", "KLP");
    cout << tree.toString("{}()[]", "LKP") << endl;
    return 0;
}