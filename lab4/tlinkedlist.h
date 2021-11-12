#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include "item.h"

class TLinkedList
{
public:
    TLinkedList();
    TLinkedList(const TLinkedList &other);

    ShOct First();
    ShOct Last();
    ShOct GetItem(size_t idx);

    size_t Length();
    bool Empty();

    void InsertFirst(ShOct octagon);
    void InsertLast(ShOct octagon);
    void Insert(ShOct octagon, size_t position);

    void RemoveFirst();
    void RemoveLast();
    void Remove(size_t position);

    friend std::ostream &operator<<(std::ostream &os, const TLinkedList &list);

    void Clear();
    virtual ~TLinkedList();

private:
    ShItem beginning;
    ShItem end;
};

#endif // TLINKEDLIST_H
