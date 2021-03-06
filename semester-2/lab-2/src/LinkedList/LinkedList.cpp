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
LinkedList<T>::~LinkedList() {
    if (size > 1) {
        Node<T>* node = first->next;

        for (int i(1); i < size - 1; i++) {
            Node<T>* tempNext = node->next;
            delete node;
            node = tempNext;
        }
    }

    size = 0;
    delete first;
}

template<class T>
void LinkedList<T>::append(T value) {
    /// @todo prepend is more basic than insertAt
    /// So, may it's better to make this with just an insertAt()

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
    /// @todo prepend is more basic than insertAt
    /// So, may it's better to make this with just an insertAt()

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
Node<T>* LinkedList<T>::getFirstNode() const {
    try
    {
        if (size == 0)
            throw "IndexOutOfRange";
        else
            return first;
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
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
void LinkedList<T>::set(int index, T item) {
    try {
        if (index < 0 || index >= size)
            throw "IndexOutOfRange";
        Node<T>* node = first;
        for (int i(0); i <= index; i++) {
            if (i == index) {
                node->value = item;
            }
            node = node->next;
        }
    }
    catch (const char* exception)     {
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
        Node<T>* node = first;
        for (int i(0); i < index + 1; i++) {
            if (i == index) {
                return node->value;
            }
            node = node->next;
        }
        return node->value;
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}

template<class T> 
T& LinkedList<T>::operator[](const int index) {
    try
    {
        if (index < 0 || index >= size)
            throw "IndexOutOfRange";
        Node<T>* node = first;
        for (int i(0); i < index + 1; i++) {
            if (i == index) {
                return node->value;
            }
            node = node->next;
        }
        return node->value;
    }
    catch (const char* exception)
    {
        cerr << "ERROR: " << exception << '\n';
        exit(0);
    }
}

/// @todo Try to optimize it
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
int LinkedList<T>::getSize() const {
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
void LinkedList<T>::swapValues(int index1, int index2) {
    Node<T>* node = first;
    Node<T>* node1 = nullptr;
    Node<T>* node2 = nullptr;

    for (int i(0); i < size; i++) {
        if (i == index1)
            node1 = node;
        if (i == index2)
            node2 = node;
        node = node->next;
    }

    Node<T>* buff = node1;
    node1->value = node2->value;
    node2->value = buff->value;
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