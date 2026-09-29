#include "Rational.h"
#include <iostream>
#include <string>

using namespace std;

Rational::Rational() {
    a = 0;
    b = 1;
}

Rational::Rational(long long numerator, long long denominator) {
    a = numerator;
    if (denominator == 0) {
        cout << "Помилка! Знаменник не може бути нулем. Встановлено 1." << endl;
        b = 1;
    }
    else {
        b = denominator;
    }
    reduce();
}

Rational::Rational(long long numerator) {
    a = numerator;
    b = 1;
}

Rational::Rational(const Rational& other) {
    a = other.a;
    b = other.b;
}

Rational::~Rational() {

}


void Rational::reduce()
{
    long long x = (a < 0) ? -a : a;
    long long y = (b < 0) ? -b : b;

    while (y != 0)
    {
        long long temp = x % y;
        x = y;
        y = temp;
    }

    if (x != 0)
    {
        a /= x;
        b /= x;
    }

    if (b < 0)
    {
        a = -a;
        b = -b;
    }
}

bool Rational::Init(long long numerator, long long denominator)
{
    if (denominator == 0)
    {
        return false;
    }

    a = numerator;
    b = denominator;

    reduce();

    return true;
}

void Rational::Read()
{
    do
    {
        cout << "Введіть чисельник: ";
        cin >> a;

        cout << "Введіть знаменник: ";
        cin >> b;

        if (b == 0)
        {
            cout << "Помилка! Знаменник не може дорівнювати нулю."
                << endl;
        }

    } while (b == 0);

    reduce();
}

void Rational::Display() const
{
    cout << toString() << endl;
}

string Rational::toString() const
{
    if (b == 1)
    {
        return to_string(a);
    }

    if (a == 0)
    {
        return "0";
    }

    return to_string(a) + "/" + to_string(b);
}

Rational Rational::add(const Rational& other) const
{
    return Rational(a * other.b + other.a * b, b * other.b);
}

Rational Rational::sub(const Rational& other) const
{
    return Rational(a * other.b - other.a * b, b * other.b);
}

Rational Rational::mul(const Rational& other) const
{
    return Rational(a * other.a, b * other.b);
}

Rational Rational::div(const Rational& other) const
{
    if (other.a == 0)
    {
        cout << "Помилка! На нуль ділити не можна." << endl;
        return Rational(0, 1);
    }

    return Rational(a * other.b, b * other.a);
}

bool Rational::equal(const Rational& other) const
{
    return a * other.b == other.a * b;
}

bool Rational::greater(const Rational& other) const
{
    return a * other.b > other.a * b;
}

bool Rational::less(const Rational& other) const
{
    return a * other.b < other.a * b;
}