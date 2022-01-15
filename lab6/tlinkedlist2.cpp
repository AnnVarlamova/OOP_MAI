#include "octagon.h"
#include "tlinkedlist2.h"
#include <iostream>

TLinkedList2::TLinkedList2() {
    first = nullptr;
}

void TLinkedList2::InsertFirst(void* link) {
    auto *other = new Item2(link);
    other->to_right(first);
    first = other;
}

void TLinkedList2::Insert(size_t position, void *link) {
    Item2 *iter = this->first;
    auto *other = new Item2(link);
    if (position == 1) {
        other->to_right(iter);
        this->first = other;
    } else {
        if (position <= this->Length()) {
            for (size_t i = 1; i < position - 1; ++i)
                iter = iter->Next();
            other->to_right(iter->Next());
            iter->to_right(other);
        }
    }
}

void TLinkedList2::InsertLast(void *link) {
    auto *other = new Item2(link);
    Item2 *iter = this->first;
    if (first != nullptr) {
        while (iter->Next() != nullptr) {
            iter = iter->to_right(iter->Next());
        }
        iter->to_right(other);
        other->to_right(nullptr);
    }
    else {
        first = other;
    }
}

size_t TLinkedList2::Length() {
    size_t len = 0;
    Item2* item = this->first;
    while (item != nullptr) {
        item = item->Next();
        len++;
    }
    return len;
}

bool TLinkedList2::Empty() {
    return first == nullptr;
}

void TLinkedList2::Remove(size_t &position) {
    Item2 *iter = this->first;
    if (position <= this->Length()) {
        if (position == 1) {
            this->first = iter->Next();
        } else {
            size_t i = 1;
            for (i = 1; i < position - 1; ++i) {
                iter = iter->Next();
            }
            iter->to_right(iter->Next()->Next());
        }

    } else {
        std::cout << "error" << std::endl;
    }
}

void TLinkedList2::Clear() {
    first = nullptr;
}

void * TLinkedList2::GetItem() {
    return this->first->GetItem();
}

TLinkedList2::~TLinkedList2() {
    delete first;
}