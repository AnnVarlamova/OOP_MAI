#ifndef ITEM2_H
#define ITEM2_H

#include <memory>

class Item2 {
public:
    Item2(void *ptr);

    Item2* to_right(Item2* next);
    Item2* Next();
    void* GetItem();

    virtual ~Item2();
private:
    void* link;
    Item2* next;
};

#endif // ITEM2_H
