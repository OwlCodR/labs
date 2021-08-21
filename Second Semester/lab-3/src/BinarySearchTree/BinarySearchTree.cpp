#include "BinarySearchTree.h"

template<class T>
BinarySearchTree<T>::BinarySearchTree() {
    log("Called empty constructor");
    root = nullptr;
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(T value) {
    log("Called value constructor");
    root = new Node<T>(value);
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(Node<T>* new_root) {
    root = new_root;
}


template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
    log("Called destructor!");
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
int BinarySearchTree<T>::getDepthOf(Node<T>* depthNode) {
    Node<T> node = root;
    int counter = 0;

    while (node != nullptr) {
        counter++;

        if (depthNode->value < node->value) {
            node = node->left; // nullptr
        } else if (depthNode->value > node->value) {
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

// Test
template<class T>
void BinarySearchTree<T>::add(T value) {
    log("add()");

    if (root == nullptr) {
        root = new Node<T>(value);
        return;
    }

    Node<T>* currentNode = root;

    while (currentNode != nullptr) {
        if (value > currentNode->value) {
            if (currentNode->right == nullptr)
                currentNode->right = new Node<T>(value);
            else
                currentNode = currentNode->right;
        }

        else if (value < currentNode->value) {
            if (currentNode->left == nullptr)
                currentNode->left = new Node<T>(value);
            else
                currentNode = currentNode->left;
        } 

        else if (value == currentNode->value) {
            break;
        }
    }
}


// Test
template<class T>
void BinarySearchTree<T>::remove(Node<T>* node) {

    if (node == nullptr) {
        return;
    }

    if (node->left != nullptr) {
        remove(node->left);
    }

    if (node->right != nullptr) {
        remove(node->right);
    }

    delete node;
}

template<class T>
void fromString(string input, string brackets, string format) {
    log("fromString()");

    /*  Example
        input = "{4}({2}(1)[3])[{5}[6]]"
        brackets = "{}[]()"
        format = "KLP"
    */
    
    if (input.length() > 0) {
        for (int i(0); i < format.size(); i++) {

            if (format[i] == 'K') {
                if (currentNode->left != nullptr || currentNode->right != nullptr)
                    result += brackets[i * 2] + to_string(currentNode->value) + brackets[i * 2 + 1];
                else
                    result += to_string(currentNode->value);
            }

            if (format[i] == 'L') {
                if (currentNode->left != nullptr) {
                    result += brackets[i * 2] + toString(currentNode->left, brackets, format) + brackets[i * 2 + 1];
                }
            }

            if (format[i] == 'P') {
                if (currentNode->right != nullptr) {
                    result += brackets[i * 2] + toString(currentNode->right, brackets, format) + brackets[i * 2 + 1];
                }
            }
        }
    }
}

template<class T>
void fromString(string subInput, string brackets, string format) {
    log("fromString()");

    /*  Example
        input = "{4}({2}(1)[3])[{5}[6]]"
        brackets = "{}[]()"
        format = "KLP"
    */
    
    fromString()
}

template<class T>
string BinarySearchTree<T>::toString(string brackets, string format) {
    log("toString()");

    /*  Example
        brackets = "{}[]()"
        format = "КЛП"
    */

    return toString(root, brackets, format);
}

template<class T>
string BinarySearchTree<T>::toString(Node<T>* subRoot, string brackets, string format) {
    string result = "";

    Node<T>* currentNode = subRoot;

    if (currentNode != nullptr) {
        for (int i(0); i < format.size(); i++) {

            if (format[i] == 'K') {
                if (currentNode->left != nullptr || currentNode->right != nullptr)
                    result += brackets[i * 2] + to_string(currentNode->value) + brackets[i * 2 + 1];
                else
                    result += to_string(currentNode->value);
            }

            if (format[i] == 'L') {
                if (currentNode->left != nullptr) {
                    result += brackets[i * 2] + toString(currentNode->left, brackets, format) + brackets[i * 2 + 1];
                }
            }

            if (format[i] == 'P') {
                if (currentNode->right != nullptr) {
                    result += brackets[i * 2] + toString(currentNode->right, brackets, format) + brackets[i * 2 + 1];
                }
            }
        }
    }

    return result;
}

//Test 
template<class T>
Node<T>* BinarySearchTree<T>::findNode(T value) {
    Node<T>* currentNode = root;

    while (currentNode != nullptr) {
        if (value > currentNode->value) {
            currentNode = currentNode->right;
        }

        if (value < currentNode->value) {
            currentNode = currentNode->left;
        }

        if (currentNode->value == value) {
            return currentNode;
        }
    }

    return nullptr;
}

// BinarySearchTree<T> BinarySearchTree<T>::findSubTree(BinarySearchTree& subTree) {
//     BinarySearchTree<T> binarySearchTree(subTree.getRoot());
// }

// template<class T>
// BinarySearchTree<T> BinarySearchTree<T>::findSubTree(Node<T>* subRoot) {
//     BinarySearchTree<T> binarySearchTree(subRoot);
// }

// template<class T>
// BinarySearchTree<T> BinarySearchTree<T>::findSubTree(T value) {
//     BinarySearchTree<T> binarySearchTree(findNode(value));
// }

// template<class T>
// Node<T>* BinarySearchTree<T>::findNodeByPath(Node<T>* node, string path) {
//     if (path.length() == 0) {
//         return node;
//     } else if (path.back() == 'L') {
//         return findNodeByPath(node->left, path.substr(0, path.length() - 1));
//     } else if (path.back() == 'R') {
//         return findNodeByPath(node->right, path.substr(0, path.length() - 1));
//     }
// }

// template<class T>
// Node<T>* BinarySearchTree<T>::findNodeByPath(string path) {
//     return findNodeByPath(getRoot(), path.substr(0, path.length() - 1));
// }

template<class T>
BinarySearchTree<T> BinarySearchTree<T>::merge(BinarySearchTree& tree1, BinarySearchTree& tree2) {
    
}

template<class T>
void BinarySearchTree<T>::log(const char text[]) {
    cout << "DEBUG | " << text << endl;
}