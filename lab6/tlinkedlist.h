#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include "item.h"

class TLinkedList{
public:
    TLinkedList();
    void InsertFirst(void *link);
    void InsertLast(void *link);
    void Insert(size_t position, void *link);
    size_t Length();
    bool Empty();
    void Remove(size_t &position);
    void Clear();

    void* GetItem();

    virtual ~TLinkedList();
private:
    Item* first;
};
#endif // TLINKEDLIST_H
