#include "tlinkedlist.h"

int main(void)
{
    TLinkedList l;
    Point x1(3, 1);
    Point x2(2, 4);
    Point x3(4, 8);
    Point x4(7, 8);
    Point x5(9, 6);
    Point x6(10, 3);
    Point x7(9, 1);
    Point x8(6, 0);

    Point y1(3, 0);
    Point y2(1, 2);
    Point y3(1, 4);
    Point y4(3, 5);
    Point y5(5, 5);
    Point y6(7, 4);
    Point y7(7, 2);
    Point y8(5, 0);

    Point z1(2, 0);
    Point z2(1, 2);
    Point z3(1, 5);
    Point z4(5, 6);
    Point z5(6, 5);
    Point z6(7, 3);
    Point z7(6, 1);
    Point z8(4, 0);

    Octagon o1(x1, x2, x3, x4, x5, x6, x7, x8);
    Octagon o2(y1, y2, y3, y4, y5, y6, y7, y8);
    Octagon o3(z1, z2, z3, z4, z5, z6, z7, z8);


    //Octagon o1, o2, o3;
    //std::cin >> o1 >> o2 >> o3;
    l.Remove(5);
    l.Insert(o1, 1);
    std::cout << l << std::endl;
    l.Insert(o1, 2);
    std::cout << l << std::endl;
    l.Insert(o1, 3);
    std::cout << l << std::endl;
    l.Insert(o3, 4);
    std::cout << l << std::endl;
    l.Insert(o3, 3);
    std::cout << l << std::endl;
    l.Insert(o2, 6);
    std::cout << l << std::endl;
    l.Insert(o2, 1);
    std::cout << l << std::endl;

    l.Remove(5);
    std::cout << l << std::endl;
    std::cout << l.Length() << std::endl;
    l.Remove(l.Length());
    std::cout << l << std::endl;
    l.RemoveFirst();
    std::cout << l << std::endl;
    l.RemoveLast();
    std::cout << l << std::endl;
    l.InsertFirst(o3);
    std::cout << l << std::endl;
    std::cout << l.GetItem(1) << std::endl;
    std::cout << l.GetItem(2) << std::endl;
    std::cout << l.GetItem(3) << std::endl;
    std::cout << l.GetItem(4) << std::endl;
    return 0;
}
