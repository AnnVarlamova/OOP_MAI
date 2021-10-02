#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

#include "figure.h"

class Triangle : public Figure {
public:
  Triangle();
  Triangle(Point a_, Point b_, Point c_);
  Triangle(std::istream &is);
  Triangle(const Triangle& other);

  size_t VertexesNumber();
  double Area();
  void Print(std::ostream& os);

  virtual ~Triangle();

  friend std::istream& operator>>(std::istream& is, Triangle& t);
  friend std::ostream& operator<<(std::ostream& os, Triangle& t);

private:
  Point A;
  Point B;
  Point C;
};

#endif // TRIANGLE_H
