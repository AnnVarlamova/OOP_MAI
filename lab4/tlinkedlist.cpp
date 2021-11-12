#include "tlinkedlist.h"

TLinkedList::TLinkedList() : beginning(nullptr), end(nullptr) {}

TLinkedList::TLinkedList(const TLinkedList &other)
{
    beginning = other.beginning;
    end = other.end;
}

ShOct TLinkedList::First()
{
    if (beginning == nullptr) {
        std::cout << "The list is empty" << std::endl;
        exit(1);
    }
    return beginning->GetOctagon();
}

ShOct TLinkedList::Last()
{
    if (end == nullptr) {
        std::cout << "The list is empty" << std::endl;
        exit(1);
    }
    return end->GetOctagon();
}

ShOct TLinkedList::GetItem(size_t position)
{
    size_t n = this->Length();
    if (beginning == nullptr) {
        std::cout << "The list is empty" << std::endl;
        exit(1);
    }
    if (position > n) {
        std::cout << "The is no such position" << std::endl;
        exit(1);
    }
    if (position == 1) {
        return beginning->GetOctagon();
    }
    if (position == n) {
        return end->GetOctagon();
    }
    ShItem node = beginning;
    for (size_t i = 1; i < position; ++i) {
        node = node->Right();
    }
    return node->GetOctagon();
}

bool TLinkedList::Empty()
{
    return (beginning == nullptr);
}

size_t TLinkedList::Length()
{
    size_t size = 0;
    for (ShItem i = beginning; i != nullptr; i = i->Right()) {
        ++size;
    }
    return size;
}

void TLinkedList::InsertFirst(ShOct octagon)
{
    ShItem node(new Item(octagon));
    if (beginning == nullptr) {
        beginning = (end = node);
        return;
    }
    node->ToLeft(nullptr);
    node->ToRight(beginning);
    beginning->ToLeft(node);
    beginning = node;
}

void TLinkedList::InsertLast(ShOct octagon)
{
    ShItem node(new Item(octagon));
    if (beginning == nullptr) {
        beginning = (end = node);
        return;
    }
    node->ToLeft(end);
    node->ToRight(nullptr);
    end->ToRight(node);
    end = node;
}

void TLinkedList::Insert(ShOct octagon, size_t position)
{
    size_t n = this->Length();
    if (position > n + 1) {
        std::cout << "The is no such position" << std::endl;
        return;
    }
    if (position == 1) {
        InsertFirst(octagon);
        return;
    }
    if (position == n + 1) {
        InsertLast(octagon);
        return;
    }
    ShItem node(new Item(octagon));
    ShItem now = beginning;
    for (size_t i = 1; i < position; ++i) {
        now = now->Right();
    }
    ShItem before = now->Left();
    before->ToRight(node);
    now->ToLeft(node);
    node->ToLeft(before);
    node->ToRight(now);
}

void TLinkedList::RemoveFirst()
{
    if (beginning == nullptr) {
        std::cout << "The list is empty" << std::endl;
        return;
    }
    if (end == beginning) {
        beginning = (end = nullptr);
        return;
    }
    ShItem node = beginning;
    beginning = beginning->Right();
    beginning->ToLeft(nullptr);
}

void TLinkedList::RemoveLast()
{
    if (end == nullptr) {
        std::cout << "The list is empty" << std::endl;
        return;
    }
    if (end == beginning) {
        beginning = (end = nullptr);
        return;
    }
    ShItem node = end;
    end = end->Left();
    end->ToRight(nullptr);
}

void TLinkedList::Remove(size_t position)
{
    size_t n = this->Length();
    if (beginning == nullptr) {
        std::cout << "The list is empty" << std::endl;
        return;
    }
    if (position > n) {
        std::cout << "The is no such position" << std::endl;
        return;
    }
    if (position == 1) {
        RemoveFirst();
        return;
    }
    if (position == n) {
        RemoveLast();
        return;
    }
    ShItem node = beginning;
    for (size_t i = 1; i < position; ++i) {
        node = node->Right();
    }
    ShItem node_left = node->Left();
    ShItem node_right = node->Right();
    node_left->ToRight(node_right);
    node_right->ToLeft(node_left);
}

std::ostream &operator<<(std::ostream &os, const TLinkedList &list)
{
    if (list.beginning == nullptr) {
        os << "List is empty" << std::endl;
        return os;
    }
    for (ShItem i = list.beginning; i != nullptr; i = i->Right()) {
        if (i->Right() != nullptr)
            os << i->GetOctagon()->Area() << " -> ";
        else
            os << i->GetOctagon()->Area();
    }
    return os;
}

void TLinkedList::Clear()
{
    while (beginning != nullptr) {
        RemoveFirst();
    }
}

TLinkedList::~TLinkedList()
{
    while (beginning != nullptr) {
        RemoveFirst();
    }
}