#ifndef ITEM_H
#define ITEM_H

#include "octagon.h"

class Item
{
public:
    Item(const Octagon &s);
    Item(const Item &other);

    Item *Left();
    Item *Right();
    
    void ToLeft(Item *node);
    void ToRight(Item *node);

    Octagon& GetOctagon();

    friend std::ostream &operator<<(std::ostream &os, const Item& node);

    virtual ~Item();

private:
    Octagon octagon;
    Item *prev;
    Item *next;
};

#endif // ITEM_H
