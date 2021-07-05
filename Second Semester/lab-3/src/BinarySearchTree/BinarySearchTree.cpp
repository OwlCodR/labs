#include "BinarySearchTree.h"

template<class T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(T value) {
    root = new Node<T>(value);
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(Node<T>* new_root) {
    root = new_root;
}


template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
    remove(root);
}


template<class T>
Node<T>* BinarySearchTree<T>::getRoot() {
    return root;
}

template<class T>
void BinarySearchTree<T>::sew() {
    // 
}

template<class T>
int BinarySearchTree<T>::getDepthOf(Node<T>* depth_node) {
    Node<T> node = root;
    int counter = 0;

    while (node != nullptr) {
        counter++;

        if (node->value > depth_node->value) {
            node = node->left; // nullptr
        } else if (node->value < depth_node->value) {
            node = node->right;
        } else {
            return counter - 1;
        }
    }

    return counter;
}

template<class T>
int BinarySearchTree<T>::getDepthOf(T value) {
    Node<T>* node(value);
    return getDepthOf(node);
}

template<class T>
int BinarySearchTree<T>::getHeight() {
    Node<T> node = root;
    stack<Node<T>*> rightNodes;
    int max_depth = 0;
    int depth = 0;
    int counter = 0;

    while (node != nullptr || !rightNodes.empty()) {
        if (node != nullptr) {
            if (node->right != nullptr)
                rightNodes.push(node->right);
            node = node->left;
            depth++;
        } else {
            node = rightNodes.top();

            if (depth > max_depth) {
                max_depth = depth;
            }

            rightNodes.pop();
            depth -= counter;
            counter = 0;
        }
    }
    return max_depth;
}

template<class T>
void BinarySearchTree<T>::add(Node<T>* new_node) {
    Node<T>* node = root;
    while (node != nullptr) {
        if (new_node->value > node->value) {
            if (node->right == nullptr) {
                node->right = new_node;
                return;
            }
            else
                node = node->right;
        } else if (new_node->value < node->value) {
            if (node->left == nullptr) {
                node->left = new_node;
                return;
            }
            else
                node = node->left;
        } else {
            return;
        }
    }

    root = new_node;
}

template<class T>
void BinarySearchTree<T>::add(T value) {
    Node<T>* node(value);
    add(node);
}

template<class T>
void BinarySearchTree<T>::remove(Node<T>* node) {
    if (node->left != nullptr) {
        remove(node->left);
    } else if (node->right != nullptr) {
        remove(node->right);
    }
    node = nullptr;
}

template<class T>
bool isNumber(char a) {
    return (a > 47 && a < 58);
}

template<class T>
BinarySearchTree<T> BinarySearchTree<T>::fromString(string input, char* brackets, char* bypass) {
    Node<T>* subRoot;

    for (int i(0); i < input.length(); i++) {
        if (isNumber(input[i])) {
            Node<T>* new_node(stoi(input[i]));
            if (input[i - 1] == brackets[0]) {
                if (subRoot == nullptr)
                    subRoot = new_node;
            } else if (input[i - 1] == brackets[2]) {
                if (subRoot->left == nullptr) 
                    subRoot->left = new_node;
            } else if (input[i - 1] == brackets[4]) {
                if (subRoot->right == nullptr) 
                    subRoot->right = new_node;
            }
        } else if (input[i] == brackets[0] || input[i] == brackets[2] || input[i] == brackets[4]) {
            // if it is open bracket
            int counter = 1;
            string subTreeInput = input[i];
            while (counter != 0) {
                i++;
                subTreeInput += input[i];
                for (int k(0); k < 6; k += 2) {
                    if (input[i] == brackets[k]) {
                        // if it is open bracket
                        counter++;
                    } else if (input[i] == brackets[k + 1]) {
                        // if it is close bracket
                        counter--;
                    }
                }
            }

            if (subTreeInput.length() > 3) {
                // if count of nodes > 1
                if (input[i] == brackets[0])
                    subRoot = fromString(subTreeInput.substr(1, input.length() - 1), brackets, bypass).getRoot();
                else if (input[i] == brackets[2])
                    subRoot->left = fromString(subTreeInput.substr(1, input.length() - 1), brackets, bypass).getRoot();
                else if (input[i] == brackets[4])
                    subRoot->right = fromString(subTreeInput.substr(1, input.length() - 1), brackets, bypass).getRoot();
            }
        }
    }

    return new BinarySearchTree(subRoot);
}

template<class T>
BinarySearchTree<T> BinarySearchTree<T>::fromString(string input, string format) {
    /*
    * Example
    * input = "{10}[{9}[7]<12>]<{13}[5]<15>>"
    * format = "{К}[Л]<П>"
    */

    char brackets[6];   // {}[][]
    char bypass[3];     // ЛПК 
    /*
    * [0] - Left root's bracket
    * [1] - Right root's bracket
    * [2], [3] - Left node's brackets
    * [4], [5] - Right node's brackets
    */

    for (int i(0); i < format.length(); i++) {
        if (format[i] == 'К') {
            bypass[i / 2] = format[i];
            brackets[0] = format[i - 1];
            brackets[1] = format[i + 1];

        } else if (format[i] == 'Л') {
            bypass[i / 2] = format[i];
            brackets[2] = format[i - 1];
            brackets[3] = format[i + 1];

        } else if (format[i] == 'П') {
            bypass[i / 2] = format[i];
            brackets[4] = format[i - 1];
            brackets[5] = format[i + 1];
        } 
    }
    
    return fromString(input, brackets, bypass);
}

template<class T>
string BinarySearchTree<T>::toString(char* brackets, char* bypass) {
    
}

template<class T>
string BinarySearchTree<T>::toString(string format) {
    char brackets[6];   // {}[][]
    char bypass[3];     // ЛПК 
    /*
    * [0] - Left root's bracket
    * [1] - Right root's bracket
    * [2], [3] - Left node's brackets
    * [4], [5] - Right node's brackets
    */

    for (int i(0); i < format.length(); i++) {
        if (format[i] == 'К') {
            bypass[i / 2] = format[i];
            brackets[0] = format[i - 1];
            brackets[1] = format[i + 1];

        } else if (format[i] == 'Л') {
            bypass[i / 2] = format[i];
            brackets[2] = format[i - 1];
            brackets[3] = format[i + 1];

        } else if (format[i] == 'П') {
            bypass[i / 2] = format[i];
            brackets[4] = format[i - 1];
            brackets[5] = format[i + 1];
        } 
    }
    
    return toString(brackets, bypass);
}

template<class T>
Node<T>* getNode(T value) {
    Node<T>* node = root;
    while (node != nullptr) {
        if (node->value > value) {
            node = node->right;
        } else if (node->value < value) {
            node = node->left;
        } else {
            return node;
        }
    }

    return nullptr;
}

template<class T>
BinarySearchTree<T> BinarySearchTree<T>::findSubTree(BinarySearchTree& subTree) {
    BinarySearchTree<T> binarySearchTree(subTree.getRoot());
}

template<class T>
BinarySearchTree<T> BinarySearchTree<T>::findSubTree(Node<T>* subRoot) {
    BinarySearchTree<T> binarySearchTree(subRoot);
}

template<class T>
BinarySearchTree<T> BinarySearchTree<T>::findSubTree(T value) {
    BinarySearchTree<T> binarySearchTree(findNode(value));
}

template<class T>
Node<T>* BinarySearchTree<T>::findNodeByPath(Node<T>* node, string path) {
    if (path.length() == 0) {
        return node;
    } else if (path.back() == 'L') {
        return findNodeByPath(node->left, path.substr(0, path.length() - 1));
    } else if (path.back() == 'R') {
        return findNodeByPath(node->right, path.substr(0, path.length() - 1));
    }
}

template<class T>
Node<T>* BinarySearchTree<T>::findNodeByPath(string path) {
    return findNodeByPath(getRoot(), path.substr(0, path.length() - 1));
}

template<class T>
BinarySearchTree<T> BinarySearchTree<T>::merge(BinarySearchTree& tree1, BinarySearchTree& tree2) {
    
}
