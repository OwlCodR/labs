#include "LinkedList.h"

template<class T>
void LinkedList<T>::init() {
    this->first = new Node<T>();
    this->last = new Node<T>();
    this->size = 0;
}

template<class T>
LinkedList<T>::LinkedList(T* items, int count) {
    init();

    for (int i(0); i < count; i++) {
        append(items[i]);
    }
}


template<class T>
LinkedList<T>::LinkedList() {
    init();
}


template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
    init();

    Node<T>* node = list.first;
    for (int i(0); i < list.getSize(); i++) {
        append(node->value);
        node = node->next;
    }
}

template<class T>
void LinkedList<T>::append(T value) {
    if (size == 0) {
        first->value = value;
        size++;
        return;
    } else if (size == 1) {
        last->value = value;
        first->next = last;
        size++;
        return;
    }

    Node<T>* node = new Node<T>(value);
    last->next = node;
    last = node;
    size++;
}

template<class T>
void LinkedList<T>::prepend(T value) {
    if (size == 0) {
        first->value = value;
        size++;
        return;
    } else if (size == 1) {
        first->next = last;
        last->value = first->value;
        first->value = value;
        last = first->next;
        size++;
        return;
    }

    Node<T>* node = new Node<T>(value);
    node->next = first;
    first = node;
    size++;
}

template<class T>
T LinkedList<T>::getFirst() {
    try
    {
        if (size == 0)
            throw "IndexOutOfRange";
        else
            return first->value;
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}


template<class T>
T LinkedList<T>::getLast() {
    try
    {
        if (size == 0)
            throw "IndexOutOfRange";
        else
            return last->value;
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}


template<class T>
T LinkedList<T>::get(int index) {
    try
    {
        if (index < 0 || index >= size)
            throw "IndexOutOfRange";
        else {
            Node<T>* node = first;
            for (int i(0); i < index + 1; i++) {
                if (i == index) {
                    return node->value;
                }
                node = node->next;
            }
        }
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}


template<class T>
LinkedList<T>* LinkedList<T>::getSubList(int startIndex, int endIndex) {
    try
    {
        if (startIndex < 0 || startIndex > size || endIndex < 0 || endIndex > size || startIndex > endIndex)
            throw "IndexOutOfRange";
        else {
            LinkedList<T>* subLinkedList = new LinkedList();

            Node<T>* node = first;
            for (int i(0); i < size; i++) {
                if (i >= startIndex && i < endIndex)
                    subLinkedList->append(node->value);
                else if (i == endIndex)
                    return subLinkedList;
                node = node->next;
            }

            return subLinkedList;
        }
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}


template<class T>
int LinkedList<T>::getSize() {
    return this->size;
}

template<class T>
void LinkedList<T>::insertAt(int index, T value) {
    try
    {
        if (index < 0 || index > size)
            throw "IndexOutOfRange";
        else {
            if (index == 0) {
                prepend(value);
                return;
            } else if (index == size) {
                append(value);
                return;
            }

            Node<T>* node = first->next;
            for (int i(1); i < size - 1; i++) {
                if (i == index - 1) {
                    Node<T>* new_node = new Node<T>(value);
                    new_node->next = node->next;
                    node->next = new_node;
                    size++;
                    return;
                }
                node = node->next;
            }
        }
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}

template<class T>
LinkedList<T>* LinkedList<T>::concat(LinkedList<T>* list) {
    LinkedList<T>* new_LinkedList = new LinkedList();
    Node<T>* node = this->first;
    for (int i(0); i < this->getSize(); i++) {
        new_LinkedList->append(node->value);
        node = node->next;
    }

    node = list->first;
    for (int i(0); i < list->getSize(); i++) {
        new_LinkedList->append(node->value);
        node = node->next;
    }

    return new_LinkedList;
}

template<class T> 
void LinkedList<T>::print(bool debug) {
    if (debug)
        cout << "LinkedList[" << size << "]: ";

    Node<T>* node = first;
    for (int i(0); i < size; i++) {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

template<class T> 
string LinkedList<T>::to_string() {
    string s = "";

    Node<T>* node = first;
    for (int i(0); i < size; i++) {
        s += std::to_string(node->value);
        if (i != size - 1)
            s += " ";
        node = node->next;
    }

    cout << "to_string() = " << s << endl;
    return s;
}