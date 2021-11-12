#ifndef ITEM_H
#define ITEM_H

#define tT template <typename T>
#define sIT std::shared_ptr<Item<T>>
#define sT std::shared_ptr<T>
#define IT Item<T>


#include "octagon.h"
#include <memory>
#include <iostream>

tT
class Item
{
public:
    Item(const sT &s);
    Item(const Item &other);

    std::shared_ptr<Item> Left();
    std::shared_ptr<Item> Right();
    
    void ToLeft(std::shared_ptr<Item> node);
    void ToRight(std::shared_ptr<Item> node);

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
