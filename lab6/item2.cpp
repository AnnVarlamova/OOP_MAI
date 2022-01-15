#include "item2.h"
#include <iostream>


Item2::Item2(void* link) {
    this->link = link;
    this->next = nullptr;
}

Item2* Item2::to_right(Item2* next) {
    Item2* set = this->next;
    this->next = next;
    return set;
}

Item2* Item2::Next() {
    return this->next;
}

void* Item2::GetItem() {
    return this->link;
}

Item2::~Item2() {}
