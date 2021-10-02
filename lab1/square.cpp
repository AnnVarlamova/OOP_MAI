#include "square.h"

#include <iostream>
#include <cmath>

Square::Square()
  : A(0.0, 0.0), B(0.0, 0.0), C(0.0, 0.0), D(0.0, 0.0) {}

Square::Square(Point a_, Point b_, Point c_, Point d_)
  : A(a_), B(b_), C(c_), D(d_) {}

Square::Square(std::istream &is) {
  is >> A >> B >> C >> D;
}

std::istream& operator>>(std::istream& is, Square& s) {
  is >> s.A >> s.B >> s.C >> s.D;
  return is;
}

std::ostream& operator<<(std::ostream& os, Square& s) {
  os << "Square: " << s.A << " " << s.B << " "  << s.D << " " << s.C;
  return os;
}

Square::Square(const Square& other)
  : Square(other.A, other.B, other.C, other.D) {}

size_t Square::VertexesNumber()
{
  return (size_t)4;
}

double Square::Area() {
  double side = A.dist(B);
  return side * side;
}

void Square::Print(std::ostream& os)
{
  std::cout << "Square: " << A << " " << B << " "  << D << " " << C << "\n";
}

Square::~Square() {}