#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

#include "figure.h"

class Square : public Figure {
public:
  Square();
  Square(Point a_, Point b_, Point c_, Point d_);
  Square(std::istream &is);
  Square(const Square& other);

  size_t VertexesNumber();
  double Area();
  void Print(std::ostream& os);

  virtual ~Square();

  friend std::istream& operator>>(std::istream& is, Square& s);
  friend std::ostream& operator<<(std::ostream& os, Square& s);

private:
  Point A;
  Point B;
  Point C;
  Point D;
};

#endif // SQUARE_H