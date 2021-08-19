#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "../Node/Node.h"
#include <string>
#include <stack>

/*
    @TODO:
    Бинарное дерево поиска
    1. Базовые операции: 
        - Вставка V
        - Поиск элемента на вхождение
        - Удаление элемента, дерева
    2. Балансировка
    3. Прошивка 
        - по фиксированному обходу
    4. Сохранение в строку
        - по фиксированному обходу
    5. Извлечение поддерева (по заданному корню)
    6. Поиск на вхождение поддерева
    7. Перегрузка операторов
    8. Слияние (Merge)
    9. Обход дерева
    10. Высота дерева
    11. Поиск узла по заданному пути, поиск по относительному пути

    - Модульные тесты
    - Тест скорости (10^4-10^5 и 10^6-10^8)
    - Пользовательский интерфейс
*/

template<class T>
class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(T value);
    ~BinarySearchTree();

    Node<T>* getRoot();
    int getDepthOf(Node<T>* node);
    int getDepthOf(T value);
    int getHeight();
    void add(Node<T>* node);
    void remove(Node<T>* node);
    void sew();
    
    void fromString(string input, string bypass);
    string toString(string bypass);
    
    BinarySearchTree getSubTree(Node<T>* subRoot);
    Node<T>* findSubTreeRoot(BinarySearchTree& subTree);
    Node<T>* findSubTreeRoot(Node<T>* subRoot);
    Node<T>* findNodeRelative(Node<T>* subRoot, string path);
    Node<T>* findNodeAbsolute(string path);
    Node<T>* findNode(T value);

    BinarySearchTree merge(BinarySearchTree& tree1, BinarySearchTree& tree2);
private:
    Node<T>* root;
};

#endif