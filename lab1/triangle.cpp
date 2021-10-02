#include "triangle.h"

#include <iostream>
#include <cmath>

Triangle::Triangle()
  : A(0.0, 0.0), B(0.0, 0.0), C(0.0, 0.0) {}

Triangle::Triangle(Point a_, Point b_, Point c_)
  : A(a_), B(b_), C(c_) {}

Triangle::Triangle(std::istream &is) {
  is >> A >> B >> C;
}

Triangle::Triangle(const Triangle& other)
  : Triangle(other.A, other.B, other.C) {}

std::istream& operator>>(std::istream& is, Triangle& t) {
  is >> t.A >> t.B >> t.C;
  return is;
}

std::ostream& operator<<(std::ostream& os, Triangle& t) {
  os << "Triangle: " << t.A << " " << t.B << " " << t.C;
  return os;
}

size_t Triangle::VertexesNumber()
{
  return (size_t)3;
}

double Triangle::Area() {
  double AB = A.dist(B);
  double BC = B.dist(C);
  double AC = A.dist(C);
  double p = (AB + BC + AC) / 2;
  return sqrt(p * (p - AB) * (p - BC) * (p - AC));
}

void Triangle::Print(std::ostream& os)
{
  std::cout << "Triangle: " << A << " " << B << " " << C << "\n";
}

Triangle::~Triangle() {}