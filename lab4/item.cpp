#include "item.h"

Item::Item(const ShOct &o)
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

ShItem Item::Left()
{
    return this->prev;
}

ShItem Item::Right()
{
    return this->next;
}

void Item::ToLeft(ShItem node)
{
    this->prev = node;
}

void Item::ToRight(ShItem node)
{
    this->next = node;
}

ShOct Item::GetOctagon()
{
    return this->octagon;
}

std::ostream &operator<<(std::ostream &os, const Item &node)
{
    os << node.octagon << std::endl;
    return os;
}

Item::~Item() {}
