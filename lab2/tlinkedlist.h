#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include "item.h"

class TLinkedList
{
public:
    TLinkedList();
    TLinkedList(const TLinkedList &other);

    const Octagon& First();
    const Octagon& Last();
    const Octagon& GetItem(size_t idx);

    size_t Length();
    bool Empty();

    void InsertFirst(const Octagon& octagon);
    void InsertLast(const Octagon& octagon);
    void Insert(const Octagon& octagon, size_t position);

    void RemoveFirst();
    void RemoveLast();
    void Remove(size_t position);

    friend std::ostream &operator<<(std::ostream &os, const TLinkedList &list);

    void Clear();
    virtual ~TLinkedList();

private:
    Item *beginning;
    Item *end;
};

#endif // TLINKEDLIST_H
