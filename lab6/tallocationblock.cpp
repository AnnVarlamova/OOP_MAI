#include "TAllocationBlock.h"

TAllocationBlock::TAllocationBlock(size_t size, size_t count) {
    used = (char *)malloc(size * count);
    for (size_t i = 0; i < count; ++i) {
        void *ptr = (void *)malloc(sizeof(void *));
        ptr = used + i * size;
        unused.InsertLast(ptr);
    }
}

void *TAllocationBlock::Allocate() {
    if (!unused.Empty()) {
        void *res = unused.GetItem();
        size_t first = 1;
        unused.Remove(first);
        std::cout << "Octagon created" << std::endl;
        return res;
    } else {
        throw std::bad_alloc();
    }
}

void TAllocationBlock::Deallocate(void *ptr) {
    unused.InsertFirst(ptr);
    std::cout << "Octagon deleted" << std::endl;
}

bool TAllocationBlock::Empty() {
    return unused.Empty();
}

size_t TAllocationBlock::Size() {
    return unused.Length();
}

TAllocationBlock::~TAllocationBlock() {
    while (!unused.Empty()) {
        size_t first = 1;
        unused.Remove(first);
    }
    free(used);
    std::cout << "destructor action" << std::endl;
}
