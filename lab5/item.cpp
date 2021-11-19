#include "item.h"

tT
IT::Item(const sT &o)
{
    this->octagon = o;
    this->next = nullptr;
    this->prev = nullptr;
}

tT
IT::Item(const IT &other)
{
    this->octagon = other.octagon;
    this->next = other.next;
    this->prev = other.prev;
}

tT
sIT IT::Left()
{
    return this->prev;
}


tT
sIT IT::Right()
{
    return this->next;
}

tT
void IT::ToLeft(sIT node)
{
    this->prev = node;
}

tT
void IT::ToRight(sIT node)
{
    this->next = node;
}


tT
sT IT::GetOctagon() const
{
    return this->octagon;
}

tT
std::ostream &operator<<(std::ostream &os, const IT& node)
{
    os << node.octagon << std::endl;
    return os;
}

tT
IT::~Item() {}

template class Item<Octagon>;
template std::ostream& operator<<(std::ostream& os, const Item<Octagon>& item);