#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#define LT TLinkedList<T>

#include "item.h"
#include "titerator.h"

tT
class TLinkedList
{
public:
    TLinkedList();
    TLinkedList(const LT &other);

    sT First();
    sT Last();
    sT GetItem(size_t idx);

    size_t Length();
    bool Empty();

    void InsertFirst(sT octagon);
    void InsertLast(sT octagon);
    void Insert(sT octagon, size_t position);

    void RemoveFirst();
    void RemoveLast();
    void Remove(size_t position);

    template <class I>
    friend std::ostream &operator<<(std::ostream &os, const TLinkedList<I> &list);

    TIterator<Item<T>, T> begin();
    TIterator<Item<T>, T> end();

    void Clear();
    virtual ~TLinkedList();

private:
    sIT beginning;
    sIT ends;
};

#endif // TLINKEDLIST_H
