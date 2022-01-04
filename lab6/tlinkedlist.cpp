#include "tlinkedlist.h"

TLinkedList::TLinkedList() {
    first = nullptr;
}

void TLinkedList::InsertFirst(void* link) {
    auto *other = new Item(link);
    other->to_right(first);
    first = other;
}

void TLinkedList::Insert(size_t position, void *link) {
    Item *iter = this->first;
    auto *other = new Item(link);
    if (position == 1) {
        other->to_right(iter);
        this->first = other;
    } else {
        if (position <= this->Length()) {
            for (int i = 1; i < position - 1; ++i)
                iter = iter->Next();
            other->to_right(iter->Next());
            iter->to_right(other);
        }
    }
}

void TLinkedList::InsertLast(void *link) {
    auto *other = new Item(link);
    Item *iter = this->first;
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

size_t TLinkedList::Length() {
    size_t len = 0;
    Item* item = this->first;
    while (item != nullptr) {
        item = item->Next();
        len++;
    }
    return len;
}

bool TLinkedList::Empty() {
    return first == nullptr;
}

void TLinkedList::Remove(size_t &position) {
    Item *iter = this->first;
    if (position <= this->Length()) {
        if (position == 1) {
            this->first = iter->Next();
        } else {
            int i = 1;
            for (i = 1; i < position - 1; ++i) {
                iter = iter->Next();
            }
            iter->to_right(iter->Next()->Next());
        }

    } else {
        std::cout << "error" << std::endl;
    }
}

void TLinkedList::Clear() {
    first = nullptr;
}

void * TLinkedList::GetItem() {
    return this->first->GetItem();
}

TLinkedList::~TLinkedList() {
    delete first;
}