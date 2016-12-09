#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "base.h"

class LinkedList {

    struct Node {
        Data* data;
        Node* next;
    };

public:

    LinkedList();

    void insert(Data* _node);
    void append(LinkedList* _llist);
    void remove();
    size_t size();
    QList<Data> toQList();
    LinkedList::Node* getFirst() const;
    LinkedList::Node* getHead() const;

private:
    size_t m_size;
    Node* first;
    Node* head;

};


#endif // LINKEDLIST_H
