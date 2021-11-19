#ifndef ITEM_H
#define ITEM_H

#define tT template <typename T>
#define sIT std::shared_ptr<Item<T>>
#define sT std::shared_ptr<T>
#define IT Item<T>
#define sI std::shared_ptr<Item>

#include "octagon.h"
#include <memory>
#include <iostream>

tT
class Item
{
public:
    Item(const sT &s);
    Item(const Item &other);

    sI Left();
    sI Right();
    
    void ToLeft(sI node);
    void ToRight(sI node);

    sT GetOctagon() const;

    template <class O>
    friend std::ostream &operator<<(std::ostream &os, const Item<O> &node);

    virtual ~Item();

private:
    sT octagon;
    sIT prev;
    sIT next;
};

#endif // ITEM_H
