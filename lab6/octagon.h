#ifndef OCTAGON_H
#define OCTAGON_H

#include <iostream>
#include "figure.h"
#include "TAllocationBlock.h"


class Octagon : public Figure
{
public:
    Octagon();
    Octagon(Point t_1, Point t_2, Point t_3, Point t_4,
            Point t_5, Point t_6, Point t_7, Point t_8);
    Octagon(const Octagon& other);
    Octagon(std::istream &is);

    Octagon &operator=(const Octagon &other);
    bool operator==(const Octagon &other);
    friend std::istream& operator>>(std::istream& is, Octagon& o);
    friend std::ostream& operator<<(std::ostream& os, const Octagon& o);

    double Area();
    size_t VertexesNumber();

    void * operator new (size_t size);
    void operator delete(void *ptr);

    virtual ~Octagon();

private:
    Point t1;
    Point t2;
    Point t3;
    Point t4;
    Point t5;
    Point t6;
    Point t7;
    Point t8;
    static TAllocationBlock block;
};

#endif // OCTAGON_H