#include "BinarySearchTree/BinarySearchTree.h"
#include "BinarySearchTree/BinarySearchTree.cpp"
#include "UI/Menu/Menu.h"
#include "UI/Menu/Menu.cpp"

#include <iostream>
#include <string>

using namespace std;

#define type int

vector<BinarySearchTree<type>> trees;
vector<string> brackets;
vector<string> formats;

void error(string text) {
    cout << "ERROR | " << text << endl;
}

bool checkTreeSize() {
    if (trees.size() == 0) {
        error("You don't have any trees!");
        return false;
    }

    return true;
}

void printTrees() {
    if (trees.size() == 0) {
        cout << "You don't have any trees :(" << endl;
    } else {
        cout << "Now you have " << trees.size() << " trees:" << endl;
        for (int i(0); i < trees.size(); i++) {
            cout << i << ". " << trees[i].toString(brackets[i], formats[i]) << endl;
        }
    }
}

void addTree() {
    string input, bracket, format;

    cout << "\nInput example \"{4}({2}(1)[3])[5]\"";
    cout << "\nInput: ";
    cin >> input;
    cout << "\nBrackets example \"{}()[]\"";
    cout << "\nBrackets: ";
    cin >> bracket;
    cout << "\nFormat example \"KLP\"";
    cout << "\nFormat: ";
    cin >> format;

    BinarySearchTree<type> tree(input, bracket, format);

    trees.push_back(tree);
    formats.push_back(format);
    brackets.push_back(bracket);

    cout << "Tree has been successfully added!\n" << endl;
}


void addTreeFast() {
    string input = "{4}({2}(1)[3])[5]";
    string bracket = "{}()[]";
    string format = "KLP";

    BinarySearchTree<type> tree(input, bracket, format);

    trees.push_back(tree);
    formats.push_back(format);
    brackets.push_back(bracket);

    cout << "Tree has been successfully added!\n" << endl;
}

void removeTree() {
    cout << "Which one do you want to remove?" << endl;
    printTrees();

    cout << "Index: ";
    int index;
    cin >> index;

    if (index < 0 || index >= trees.size()) {
        error("Wrong index!");
        return;
    }

    trees.erase(std::next(trees.begin(), index));

    cout << "Tree has been successfully removed!" << endl;
}

void addNode() {
    if (!checkTreeSize())
        return;

    cout << "Which one do you want to add?" << endl;
    printTrees();

    cout << "Index: ";
    int index;
    cin >> index;

    if (index < 0 || index >= trees.size()) {
        error("Wrong index!");
        return;
    }

    cout << "Value: ";
    type answer;
    cin >> answer;

    trees[index].add(answer);

    cout << "Value has been successfully added!" << endl;
}

void removeNode() {
    if (!checkTreeSize())
        return;

    cout << "Which one do you want to remove node from?" << endl;
    printTrees();

    cout << "Index: ";
    int index;
    cin >> index;

    if (index < 0 || index >= trees.size()) {
        error("Wrong index!");
        return;
    }

    cout << "Value: ";
    type answer;
    cin >> answer;

    trees[index].remove(answer);

    cout << "Value has been successfully removed!" << endl;
}

void findNode() {
    if (!checkTreeSize())
        return;

    cout << "Which one do you want to find in?" << endl;
    printTrees();

    cout << "Index: ";
    int index;
    cin >> index;

    if (index < 0 || index >= trees.size()) {
        error("Wrong index!");
        return;
    }

    cout << "Value: ";
    type answer;
    cin >> answer;

    Node<type>* node = trees[index].findNode(answer);

    cout << "Node has been successfully found!" << endl;
    cout << "Node address = " << node << endl;
    cout << "Node value = " << node->value << endl;
}

void getSubTree() {
    if (!checkTreeSize())
        return;

    cout << "Which one do you want to find in?" << endl;
    printTrees();

    cout << "Index: ";
    int index;
    cin >> index;

    if (index < 0 || index >= trees.size()) {
        error("Wrong index!");
        return;
    }

    cout << "Root value: ";
    type answer;
    cin >> answer;

    BinarySearchTree<type> subTree = trees[index].findSubTree(answer);

    cout << "Subtree has been successfully found!" << endl;
    cout << "Subtree: " << subTree.toString(brackets[index], formats[index]) << endl;
}

void getHeight() {
    if (!checkTreeSize())
        return;

    cout << "Which tree height do you want to get?" << endl;
    printTrees();

    cout << "Index: ";
    int index;
    cin >> index;

    if (index < 0 || index >= trees.size()) {
        error("Wrong index!");
        return;
    }

    cout << "Subtree has been successfully found!" << endl;
    cout << "Height: " << trees[index].getHeight() << endl;
}


int main() {

    Menu menu;
    menu.addFunction("My trees", printTrees);
    menu.addFunction("Add tree", addTree);
    menu.addFunction("Add tree [FAST]", addTreeFast);
    menu.addFunction("Remove tree", removeTree);
    menu.addFunction("Add node to the tree", addNode);
    menu.addFunction("Remove node from the tree", removeNode);
    menu.addFunction("Find node in a tree", findNode);
    menu.addFunction("Find subtree in the tree", getSubTree);
    menu.addFunction("Get height of tree", getHeight);
    menu.start();

    return 0;
}