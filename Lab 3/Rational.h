#include <string>

class Rational
{
private:
    long long a;
    long long b;

    void reduce();

public:
    Rational();                                          
    Rational(long long numerator, long long denominator); 
    Rational(long long numerator);                        
    Rational(const Rational& other);                      

    ~Rational();

    bool Init(long long numerator, long long denominator);

    void Read();

    void Display() const;

    std::string toString() const;

    Rational add(const Rational& other) const;
    Rational sub(const Rational& other) const;
    Rational mul(const Rational& other) const;
    Rational div(const Rational& other) const;

    bool equal(const Rational& other) const;
    bool greater(const Rational& other) const;
    bool less(const Rational& other) const;
};