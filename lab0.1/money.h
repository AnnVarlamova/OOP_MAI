#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money
{
public:
    Money();
    Money(unsigned long long rubles, uint16_t penny);
    Money(const Money &other);
    Money(std::istream &is);
    Money &operator=(const Money &other);

    unsigned long long getRub() const;
    uint16_t getKop() const;

    friend Money operator+(const Money& one, const Money &other);
	friend Money operator-(const Money& one, const Money& other);
    friend double operator/(const Money& one, const Money& other);
    friend Money operator/(const Money& one, double arg);
    friend Money operator*(const Money& one, double arg);

    bool operator==(const Money &other);
    bool operator>(const Money &other);
	bool operator<(const Money &other);
    bool operator<=(const Money &other);
    bool operator>=(const Money &other);
    bool operator!=(const Money &other);
    
    friend std::istream &operator>>(std::istream &is, Money &m);
    friend std::ostream &operator<<(std::ostream &os, const Money &m);
    
    virtual ~Money();
private:
    unsigned long long rub;
    uint16_t kop;
};

#endif // MONEY_H

/*
Создать класс Money для работы с денежными суммами.
Сумма денег должна быть представлено двумя полями: типа unsigned long long для рублей и типа uint16_t – для копеек.
Дробная часть (копейки) при выводе на экран должна быть отделена от целой части запятой.
Реализовать сложение сумм, вычитание, деление сумм, деление суммы на дробное число, yмножение на дробное число и операции сравнения.
*/