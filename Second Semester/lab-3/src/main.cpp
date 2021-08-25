#include "BinarySearchTree/BinarySearchTree.h"
#include "BinarySearchTree/BinarySearchTree.cpp"

#include <iostream>
#include <string>

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
    tree.fromString("{4}({2}(1)[3])[34]", "{}()[]", "KLP");
    //cout << tree.toString("{}()[]", "KLP") << endl;
    BinarySearchTree<int> tree2 = tree.findSubTree(2);
    //cout << tree2.toString("{}()[]", "KLP") << endl;
    BinarySearchTree<int> tree3 = tree.findSubTree(tree2);

    cout << tree;

    cout << tree.getHeight() << endl;
    cout << tree2.getHeight() << endl;
    cout << tree3.getHeight() << endl;

    return 0;
}