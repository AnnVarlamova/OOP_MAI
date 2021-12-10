#include "money.h"

Money::Money()
    : rub(0), kop(0) {}

Money::Money(unsigned long long rubles, uint16_t penny)
    : rub(rubles), kop(penny) {}

Money::Money(const Money &other)
    : Money(other.rub, other.kop) {}

Money::Money(std::istream &is)
{
    is >> rub >> kop;
}

unsigned long long Money::getRub() const {
    return rub;
}

uint16_t Money::getKop() const {
    return kop;
}

Money &Money::operator=(const Money &other)
{
    if (this == &other) {
        return *this;
    }
    rub = other.rub;
    kop = other.kop;
    return *this;
}

Money operator+(const Money& one, const Money& other) {
    Money temp;
    temp.rub = one.rub + other.rub;
    temp.kop = one.kop + other.kop;
    if(temp.kop >= 100) {
        temp.rub++;
        temp.kop -= 100;
    }
    return temp;
}

Money operator-(const Money& one, const Money& other) {
    Money temp;
    Money r = one;
    temp.rub = one.rub - other.rub;
    if(one.kop < other.kop) {
        temp.rub--;
        r.kop = one.kop + 100;
        temp.kop = one.kop - other.kop;
        r.kop -= 100;
    }
    else temp.kop = one.kop - other.kop;
    return temp;
}

double operator/(const Money& one, const Money& other) {
    double temp, a, b;
    a = ((one.rub * 100) + one.kop);
    b = (( other. rub * 100) + other. kop);
    temp = a / b;
    return temp;
}

Money operator/(const Money& one, double arg) {
    Money temp;
    double tempN;
    tempN = (((one.rub * 100) + one.kop) / arg) / 100;
    temp. rub = (int)tempN;
    temp. kop = (tempN - (int)tempN) * 100;
    return temp;
}

Money operator*(const Money& one, double arg) {
    Money temp;
    double tempN;
    tempN = (((one.rub * 100) + one.kop) * arg);
    temp. rub = (int)(tempN / 100);
    temp. kop = (tempN / 100 - (int)(tempN / 100)) * 100;
    return temp;
}

bool Money::operator==(const Money& other) {
    return (this->rub == other.rub && this->kop == other.kop);
}

bool Money::operator>(const Money& other) {
    return (this->rub > other.rub || (this->rub == other.rub && this->kop > other.kop));
}

bool Money::operator<(const Money& other) {
    return (this->rub < other.rub || (this->rub == other.rub && this->kop < other.kop));
}

bool Money::operator<=(const Money& other) {
    return (this->rub <= other.rub && this->kop <= other.kop);
}

bool Money::operator>=(const Money& other) {
    return (this->rub >= other.rub && this->kop >= other.kop);
}

bool Money::operator!=(const Money& other) {
    return (this->rub != other.rub || this->kop !=other.kop);
}

std::istream& operator>>(std::istream& is, Money& m)
{
    is >> m.rub >> m.kop;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Money& m)
{
    os << m.rub << ",";
    if(m.kop <= 0) {
        os << "00" << std::endl;
    }
    else os << m.kop << std::endl;
    return os;
}

long double operator""_toCop(long double cop) {
    return (cop / 100);
}

Money::~Money() {}