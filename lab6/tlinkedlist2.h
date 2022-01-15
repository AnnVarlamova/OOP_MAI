#ifndef TLINKEDLIST2_H
#define TLINKEDLIST2_H


#include "item2.h"
#include "titerator.h"
#include <memory>
#include <iostream>

class TLinkedList2{
public:
    TLinkedList2();
    void InsertFirst(void *link);
    void InsertLast(void *link);
    void Insert(size_t position, void *link);
    size_t Length();
    bool Empty();
    void Remove(size_t &position);
    void Clear();

    void* GetItem();

    virtual ~TLinkedList2();
private:
    Item2* first;
};
#endif // TLINKEDLIST2_H
