#include "item.h"
#include <iostream>

Item::Item(void* link) {
    this->link = link;
    this->next = nullptr;
}

Item* Item::to_right(Item* next) {
    Item* set = this->next;
    this->next = next;
    return set;
}

Item* Item::Next() {
    return this->next;
}

void* Item::GetItem() {
    return this->link;
}

Item::~Item() {}
