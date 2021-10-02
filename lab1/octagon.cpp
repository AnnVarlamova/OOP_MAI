#include "octagon.h"

#include <iostream>
#include <cmath>

Octagon::Octagon()
  : t1(0.0, 0.0), t2(0.0, 0.0), t3(0.0, 0.0), t4(0.0, 0.0),
  t5(0.0, 0.0), t6(0.0, 0.0), t7(0.0, 0.0), t8(0.0, 0.0) {}

Octagon::Octagon(Point t_1, Point t_2, Point t_3, Point t_4,
                Point t_5, Point t_6, Point t_7, Point t_8)
  : t1(t_1), t2(t_2), t3(t_3), t4(t_4),
  t5(t_5), t6(t_6), t7(t_7), t8(t_8) {}

Octagon::Octagon(std::istream &is) {
  is >> t1 >> t2 >> t3 >> t4 >> t5 >> t6 >> t7 >> t8;
}

Octagon::Octagon(const Octagon& other)
  : Octagon(other.t1, other.t2, other.t3, other.t4,
            other.t5, other.t6, other.t7, other.t8) {}

std::istream& operator>>(std::istream& is, Octagon& o) {
  is >> o.t1 >> o.t2 >> o.t3 >> o.t4 >> o.t5 >> o.t6 >> o.t7 >> o.t8;
  return is;
}

std::ostream& operator<<(std::ostream& os, Octagon& o) {
  os << "Octagon: " << o.t1 << " " << o.t2 << " " << o.t3 << " " << o.t4
            << " " << o.t5 << " " << o.t6 << " " << o.t7 << " " << o.t8;
  return os;
}

size_t Octagon::VertexesNumber()
{
  return (size_t)8;
}

double Heron(Point A, Point B, Point C) {
  double AB = A.dist(B);
  double BC = B.dist(C);
  double AC = A.dist(C);
  double p = (AB + BC + AC) / 2;
  return sqrt(p * (p - AB) * (p - BC) * (p - AC));
}

double Octagon::Area() {
  double area1 = Heron(t1, t2, t3);
  double area2 = Heron(t1, t4, t3);
  double area3 = Heron(t1, t4, t5);
  double area4 = Heron(t1, t5, t6);
  double area5 = Heron(t1, t6, t7);
  double area6 = Heron(t1, t7, t8);
  return area1 + area2 + area3 + area4 + area5 + area6;
}

void Octagon::Print(std::ostream& os)
{
  std::cout << "Octagon: " << t1 << " " << t2 << " " << t3 << " " << t4
            << " " << t5 << " " << t6 << " " << t7 << " " << t8 << "\n";
}

Octagon::~Octagon() {}