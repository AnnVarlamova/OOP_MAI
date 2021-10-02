#ifndef OCTAGON_H
#define OCTAGON_H

#include <iostream>

#include "figure.h"

class Octagon : public Figure {
public:
  Octagon();
  Octagon(Point t_1, Point t_2, Point t_3, Point t_4,
          Point t_5, Point t_6, Point t_7, Point t_8);
  Octagon(std::istream &is);
  Octagon(const Octagon& other);

  size_t VertexesNumber();
  double Area();
  void Print(std::ostream& os);

  virtual ~Octagon();

  friend std::istream& operator>>(std::istream& is, Octagon& o);
  friend std::ostream& operator<<(std::ostream& os, Octagon& o);

private:
  Point t1;
  Point t2;
  Point t3;
  Point t4;
  Point t5;
  Point t6;
  Point t7;
  Point t8;
};

#endif // OCTAGON_H