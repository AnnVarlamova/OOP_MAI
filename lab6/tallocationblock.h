#ifndef TALLOCATIONBLOCK_H
#define TALLOCATIONBLOCK_H

#include <iostream>
#include "tlinkedlist.cpp"

class TAllocationBlock {
public:
    TAllocationBlock(size_t size, size_t count);

    void *Allocate();
    void Deallocate(void *ptr);
    bool Empty();
    size_t Size();

    virtual ~TAllocationBlock();

private:
    char *used;
    TLinkedList unused;
};

#endif //TALLOCATIONBLOCK_H
