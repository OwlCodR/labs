#include "Tests.h"

void Tests::testAddTime(int size) {
    for (int i(0); i < size; i++) {
        for (int count(1000000); count < 100000000; count += 5000000) {
            BinarySearchTree<int> tree;

            int startTime = clock();
            for (int j(0); j < count; j++) {
                tree.add(rand() % 1000000 + 0);
            }
            int endTime = clock();
            cout << "(" << count << ";" << endTime - startTime << ")" << endl;
        }
    }
}

void Tests::startTests() {
    // assert(to_string(*concat, true) == "100 1 2 3 4 100 5 6 7 8 9 10 100");
}