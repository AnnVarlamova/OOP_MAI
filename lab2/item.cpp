#include "item.h"

Item::Item(const Octagon &o)
{
    this->octagon = o;
    this->next = nullptr;
    this->prev = nullptr;
}

Item::Item(const Item &other)
{
    this->octagon = other.octagon;
    this->next = other.next;
    this->prev = other.prev;
}

Item *Item::Left()
{
    return this->prev;
}

Item *Item::Right()
{
    return this->next;
}

void Item::ToLeft(Item *node)
{
    this->prev = node;
}

void Item::ToRight(Item *node)
{
    this->next = node;
}

Octagon& Item::GetOctagon()
{
    return this->octagon;
}

std::ostream &operator<<(std::ostream &os, const Item &node)
{
    os << node.octagon << std::endl;
    return os;
}

Item::~Item() {}
