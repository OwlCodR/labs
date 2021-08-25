#include "BinarySearchTree.h"

bool isBracket(char c, string brackets) {
    for (int i(0); i < brackets.length(); i++)
        if (c == brackets[i])
            return true;

    return false;
}

bool isOtherOpened(int counters[]) {
    for (int i(0); i < 3; i++)
        if (counters[i] > 0)
            return true;

    return false;
}

bool containsBracket(string a, string brackets) {
    for (int i(0); i < brackets.length(); i++)
        if (a.find(brackets[i], 0) != string::npos)
            return true;

    return false;
}

/**
 * @brief Recursively compares nodes and their childs
 *
 * @tparam T Any if == operator is overloaded
 * @param node1 First node to be compare
 * @param node2 Second node to be compare
 * @return true if two nodes and their child-nodes are equal
 * @return false if two nodes or any of their child-nodes are different
 */
template <class T>
bool BinarySearchTree<T>::areNodesEqual(Node<T>* node1, Node<T>* node2) {
    if (node1 == nullptr && node2 == nullptr)
        return true;

    if (node1 != nullptr && node2 != nullptr) {
        if (node1->value == node2->value) {
            if (areNodesEqual(node1->left, node2->left) && areNodesEqual(node1->right, node2->right))
                return true;
            else
                return false;
        } else
            return false;
    }

    return false;
}

template <class T>
void BinarySearchTree<T>::log(const char text[]) const
{
    cout << "DEBUG | " << text;
}

/**
 * @brief Converts string to template class object.
 * This function uses <istringstream>.
 *
 * @tparam T Any if >> operator is overloaded
 * @param input string with object. Example "12.3"
 * @return T Converted object. Example 12.3 (double)
 */
template <class T>
T BinarySearchTree<T>::toObjectT(string input) {
    istringstream ss(input);
    T number;
    ss >> number;
    return number;
}

/**
 * @brief Construct a new Binary Search Tree<T>:: Binary Search Tree object
 *
 * @tparam T Any
 */
template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    log("Called empty constructor\n");
    root = nullptr;
}

/**
 * @brief Construct a new Binary Search Tree<T>:: Binary Search Tree object with root's value
 *
 * @tparam T Any
 * @param value Value of the root
 */
template <class T>
BinarySearchTree<T>::BinarySearchTree(T value)
{
    log("Called value constructor with root = ");
    cout << value << endl;

    root = new Node<T>(value);
}

// Test
template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& tree) : BinarySearchTree(tree.getRoot())
{
    log("Called copy constructor\n");
}

// Test
template <class T>
BinarySearchTree<T>::BinarySearchTree(Node<T>* newRoot)
{
    log("Called node constructor\n");
    root = nullptr;

    if (newRoot != nullptr) {
        root = new Node<T>(newRoot->value);

        log("with root = ");
        cout << newRoot->value << endl;
    }

    copyNode(newRoot, root);
}

// Test
/**
 * @brief Recursively copies nodes from one root to another.
 * This function changes only "to" node.
 *
 * @tparam T int, double, float
 * @param from The node to copy from [const]
 * @param to The node to copy to
 */
template <class T>
void BinarySearchTree<T>::copyNode(const Node<T>* from, Node<T>* to) {

    if (from == nullptr) {
        return;
    }

    if (from->left != nullptr) {
        to->left = new Node<T>(from->left->value);
        copyNode(from->left, to->left);
    }

    if (from->right != nullptr) {
        to->right = new Node<T>(from->right->value);
        copyNode(from->right, to->right);
    }
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    log("Called destructor with root = ");
    if (root != nullptr)
        cout << root->value << endl;

    remove(root);
}

template <class T>
Node<T>* BinarySearchTree<T>::getRoot()
{
    return root;
}

template <class T>
Node<T>* BinarySearchTree<T>::getRoot() const
{
    return root;
}


template <class T>
void BinarySearchTree<T>::sew()
{
    //
}

template <class T>
int BinarySearchTree<T>::getDepthOf(Node<T>* depthNode)
{
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

template <class T>
int BinarySearchTree<T>::getDepthOf(T value)
{
    Node<T>* node(value);
    return getDepthOf(node);
}

template <class T>
int BinarySearchTree<T>::getHeight()
{
    return getHeight(root, 0);
}

// Test
template <class T>
int BinarySearchTree<T>::getHeight(Node<T>* subRoot, int counter)
{
    if (subRoot == nullptr)
        return counter;
    
    int leftHeight = getHeight(subRoot->left, counter + 1);
    int rightHeight = getHeight(subRoot->right, counter + 1);

    if (leftHeight > rightHeight) 
        return leftHeight;
    else 
        return rightHeight;
}

// Test
/**
 * @brief Adds node to the binary search tree using comparison rules.
 * This function requires overloaded >, <, == operators
 *
 * @tparam T int, double, float
 * @param value Value of node by which the comparison is made
 */
template <class T>
void BinarySearchTree<T>::add(T value)
{
    log("add()\n");

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

        } else if (value < currentNode->value) {
            if (currentNode->left == nullptr)
                currentNode->left = new Node<T>(value);
            else
                currentNode = currentNode->left;

        } else if (value == currentNode->value) {
            break;
        }
    }
}

// Test
/**
 * @brief Recursively removes node and it's childs from tree.
 * This function uses "delete".
 *
 * @tparam T any
 * @param node The node to delete
 */
template <class T>
void BinarySearchTree<T>::remove(Node<T>* node)
{
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
    node = nullptr;
}

// Test
/**
 * @brief Reads tree from a string.
 * This function uses converting from string to object with toObjectT()
 *
 * @tparam T int, double, float
 * @param input String of tree. Example "{4}({2}(1)[3])[5]"
 * @param brackets String of brackets with length = 6. Example "{}()[]"
 * @param format Traversal letter string
 */
template <class T>
void BinarySearchTree<T>::fromString(string input, string brackets, string format)
{
    log("fromString()\n");
    fromString(input, brackets);
}

template <class T>
void BinarySearchTree<T>::fromString(string input, string brackets)
{
    if (input.length() > 0) {
        // "{4}({2}(1)[3])[5]"
        // "{4}({2}(1)[3])[{2}(1)[3]]"
        // "((1){2}[(1){2}[3]]){4}[5]"

        int counters[] = { 0, 0, 0 };

        // pair<startIndex, endIndex>
        vector<pair<int, int>> indexes;

        for (int i(0); i < 3; i++)
            indexes.push_back(pair<int, int>(-1, -1));

        for (int i(0); i < input.length(); i++) {
            for (int j(0); j < 3; j++) {
                if (input[i] == brackets[j * 2]) {
                    if (counters[j] == 0 && indexes[j].first == -1)
                        if (!isOtherOpened(counters))
                            indexes[j] = pair<int, int>(i, -1);

                    counters[j]++;

                } else if (input[i] == brackets[j * 2 + 1]) {
                    counters[j]--;

                    if (counters[j] == 0 && indexes[j].second == -1) {
                        if (!isOtherOpened(counters))
                            indexes[j] = pair<int, int>(indexes[j].first, i);
                    }
                }
            }
        }

        for (int i(0); i < 3; i++) {
            string subInput = input.substr(indexes[i].first + 1, indexes[i].second - indexes[i].first - 1);

            if (subInput.length() > 0 && containsBracket(subInput, brackets)) {
                fromString(subInput, brackets);
            } else {
                add(toObjectT(subInput));
            }
        }
    }
}


// Test
/**
 * @brief Writes tree to string. [const]
 *
 * @tparam T int, double, float @todo
 * @param brackets String of brackets, for example "(){}[]"
 * @param format String of traversal (KLP, LKP, PLK, etc.)
 * @return String of tree. Exmaple "{4}({2}(1)[3])[5]"
 */
template <class T>
string BinarySearchTree<T>::toString(string brackets, string format) const
{
    log("toString()\n");
    return toString(root, brackets, format);
}

/**
 * @brief Recursively writes tree to string. [const]
 *
 * @tparam T
 * @param subRoot
 * @param brackets
 * @param format
 * @return string
 */
template <class T>
string BinarySearchTree<T>::toString(Node<T>* subRoot, string brackets, string format) const
{
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
                if (currentNode->left != nullptr)
                    result += brackets[i * 2] + this->toString(currentNode->left, brackets, format) + brackets[i * 2 + 1];
            }

            if (format[i] == 'P') {
                if (currentNode->right != nullptr)
                    result += brackets[i * 2] + this->toString(currentNode->right, brackets, format) + brackets[i * 2 + 1];
            }
        }
    }

    return result;
}

// Test
/**
 * @brief Finds node in a tree by value.
 * This function requires overloaded >, <, == operators
 *
 * @tparam T int, double, float
 * @param value Value to search by
 * @return Node<T>* Pointer to the founded node. It can be nullptr.
 */
template <class T>
Node<T>* BinarySearchTree<T>::findNode(T value)
{
    Node<T>* currentNode = root;

    while (currentNode != nullptr) {
        if (value > currentNode->value) {
            currentNode = currentNode->right;
        }

        else if (value < currentNode->value) {
            currentNode = currentNode->left;
        }

        else if (currentNode->value == value) {
            return currentNode;
        }
    }

    return nullptr;
}

// Test
/**
 * @brief Finds child tree by value.
 * This function uses findNode() and copy constructor.
 *
 * @tparam T as in findNode()
 * @param value Value to search by
 * @return BinarySearchTree<T> Clone of the original founded child tree. It can be nullptr.
 */
template <class T>
BinarySearchTree<T> BinarySearchTree<T>::findSubTree(T value) {
    Node<T>* subRoot = findNode(value);

    if (subRoot != nullptr) {
        BinarySearchTree<T> subTree(subRoot);
        return subTree;
    }

    return nullptr;
}

// Test
/**
 * @brief Finds child tree for an entry by another tree.
 * Returns child tree if all nodes are equal else nullptr.
 *
 * @tparam T as in findNode()
 * @param subTree Child tree to search by
 * @return BinarySearchTree<T> Clone of the original founded child tree. It can be nullptr.
 */
template <class T>
BinarySearchTree<T> BinarySearchTree<T>::findSubTree(BinarySearchTree<T>& subTree) {
    Node<T>* subRoot = findNode(subTree.getRoot()->value);

    if (subRoot != nullptr && areNodesEqual(subRoot, subTree.getRoot())) {
        return subTree;
    }

    return nullptr;
}

template <class T>
BinarySearchTree<T> BinarySearchTree<T>::merge(BinarySearchTree& tree1, BinarySearchTree& tree2)
{
    
}

template<class T>
bool operator==(const BinarySearchTree<T>& tree1, const BinarySearchTree<T>& tree2) {
    return areNodesEqual(tree1.getRoot(), tree2.getRoot());
}

template<class T>
ostream& operator<<(ostream& stream, const BinarySearchTree<T>& tree)
{
    stream << tree.toString("{}()[]", "KLP") << endl;
    return stream;
}
