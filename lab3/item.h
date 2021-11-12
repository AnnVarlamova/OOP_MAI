#ifndef ITEM_H
#define ITEM_H

#include "octagon.h"
#include <memory>

#define ShOct std::shared_ptr<Octagon>
#define ShItem std::shared_ptr<Item>

class Item
{
public:
    Item(const ShOct &s);
    Item(const Item &other);

    ShItem Left();
    ShItem Right();
    
    void ToLeft(ShItem node);
    void ToRight(ShItem node);

    ShOct GetOctagon();

    friend std::ostream &operator<<(std::ostream &os, const Item& node);

    virtual ~Item();

private:
    ShOct octagon;
    ShItem prev;
    ShItem next;
};

#endif // ITEM_H
