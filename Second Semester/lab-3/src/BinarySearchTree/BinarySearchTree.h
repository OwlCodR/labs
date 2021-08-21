#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "../Node/Node.h"
#include <string>
#include <stack>

/*
*    @TODO:
*    >> Бинарное дерево поиска
*    • Базовые операции: 
*        - Вставка V
*        - Поиск элемента на вхождение V
*        - Удаление элемента V
*    • Балансировка
*    • Прошивка 
*        - по фиксированному обходу
*    • Сохранение в строку
*        - по обходу, задаваемому строкой форматирования (например: «{К}(Л)[П]») V
*    • Извлечение поддерева (по заданному корню)
*    • Поиск на вхождение поддерева
*    • Перегрузка операторов
*    • Слияние (Merge)
*    • Обход дерева
*    • Высота дерева
*    • Поиск узла по заданному пути, поиск по относительному пути
*
*    - Модульные тесты
*    - Тест скорости (10^4-10^5 и 10^6-10^8)
*    - Пользовательский интерфейс
*/

template<class T>
class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(T value);
    BinarySearchTree(Node<T>* new_root);
    ~BinarySearchTree();

    Node<T>* getRoot();
    Node<T>* findNode(T value);
    int getDepthOf(Node<T>* node);
    int getDepthOf(T value);
    int getHeight();
    void add(T value);
    void remove(Node<T>* node);
    void sew(); // Прошивка

    void fromString(string input, string brackets, string format);
    string toString(string brackets, string format);

    BinarySearchTree getSubTree(Node<T>* subRoot);
    Node<T>* findSubTreeRoot(BinarySearchTree& subTree);
    Node<T>* findSubTreeRoot(Node<T>* subRoot);
    Node<T>* findNodeRelative(Node<T>* subRoot, string path);
    Node<T>* findNodeAbsolute(string path);

    // BinarySearchTree<T> findSubTree(BinarySearchTree& subTree);
    // BinarySearchTree<T> findSubTree(Node<T>* subRoot);
    // BinarySearchTree<T> findSubTree(T value);
    // Node<T>* findNodeByPath(Node<T>* node, string path);
    // Node<T>* findNodeByPath(string path);

    BinarySearchTree<T> merge(BinarySearchTree<T>& tree1, BinarySearchTree<T>& tree2);
private:
    Node<T>* root;

    string toString(Node<T>* subRoot, string brackets, string format);
    
    void log(const char text[]);
};

#endif