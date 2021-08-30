#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "../Node/Node.h"
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <iostream>

/**
 *      @TODO:
 *      >> Бинарное дерево поиска
 *      • Базовые операции: V
 *          - Вставка V
 *          - Поиск элемента на вхождение V
 *          - Удаление элемента V
 *      • Балансировка
 *      • Прошивка
 *          - по фиксированному обходу
 *      • Сохранение в строку V
 *          - по обходу, задаваемому строкой форматирования (например: «{К}(Л)[П]») V
 *      • Чтение из строки в соответствии с заданным обходом V
 *          - по обходу, задаваемому строкой форматирования (например: «{К}(Л)[П]») V
 *      • Извлечение поддерева (по заданному корню) V
 *      • Поиск на вхождение поддерева V
 *      • Перегрузка операторов V
 *      • Слияние (Merge)
 *      • Обход дерева
 *      • Высота дерева V
 *      • Поиск узла по заданному пути, поиск по относительному пути
 *
 *      - Модульные тесты
 *      - Тест скорости (10^4-10^5 и 10^6-10^8) ~
 *      - Пользовательский интерфейс V
 */

 /**
  *  For custom types override >> and << operators
  */

template <class T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(T value);
    BinarySearchTree(Node<T>* new_root);
    BinarySearchTree(const BinarySearchTree<T>& tree);
    BinarySearchTree(string input, string brackets, string format);
    ~BinarySearchTree();

    Node<T>* getRoot();
    Node<T>* getRoot() const;
    void setRoot(Node<T>* newRoot);

    Node<T>* findNode(T value);
    Node<T>* findParentNode(Node<T>* node);
    int getDepthOf(Node<T>* node);
    int getDepthOf(T value);
    int getHeight();

    void add(T value);
    void remove(T value);

    void sew();

    void fromString(string input, string brackets, string format, bool debug);
    string toString(string brackets, string format) const;
    string toString() const;

    BinarySearchTree<T> findSubTree(T value);
    BinarySearchTree<T> findSubTree(BinarySearchTree<T>& subTree);
    BinarySearchTree<T> merge(BinarySearchTree<T>& tree1, BinarySearchTree<T>& tree2);

    BinarySearchTree<T>& operator=(const BinarySearchTree<T>& tree);
private:
    Node<T>* root;

    void remove(Node<T>* node);

    void fromString(string input, string brackets, string format);
    string toString(Node<T>* subRoot, string brackets, string format) const;

    void copyNode(const Node<T>* from, Node<T>* to);
    bool areNodesEqual(Node<T>* node1, Node<T>* node2);

    int getHeight(Node<T>* subRoot, int counter);

    void log(const char text[]) const;
    T toObjectT(string s);
};

template<class T>
bool operator==(const BinarySearchTree<T>& tree1, const BinarySearchTree<T>& tree2);

template<class T>
ostream& operator<<(ostream& stream, const BinarySearchTree<T>& tree);

#endif