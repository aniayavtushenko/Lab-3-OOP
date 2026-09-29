#include <iostream>
#include "Rational.h"
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "--- Демонстрація роботи конструкторів ---" << endl;

    // 1. Використання конструктора за замовчуванням
    Rational r_default;
    cout << "1. Конструктор за замовчуванням: ";
    r_default.Display();

    // 2. Використання конструктора з двома параметрами
    Rational r_param(10, 15);
    cout << "2. Конструктор з двома параметрами : ";
    r_param.Display();

    // 3. Використання конструктора з одним параметром
    Rational r_single(7);
    cout << "3. Конструктор з одним параметром : ";
    r_single.Display();

    // 4. Використання конструктора копіювання
    Rational r_copy = r_param;
    cout << "4. Конструктор копіювання (копія другого дробу): ";
    r_copy.Display();

    cout << "\n--- Основна робота програми ---" << endl;

    Rational r1, r2;

    cout << "Перший дріб:" << endl;
    r1.Read();

    cout << "Перший дріб після скорочення: ";
    r1.Display();

    cout << endl;

    cout << "Другий дріб:" << endl;
    r2.Read();

    cout << "Другий дріб після скорочення: ";
    r2.Display();

    cout << endl;

    Rational sum = r1.add(r2);
    cout << "Додавання: ";
    sum.Display();

    Rational v = r1.sub(r2);
    cout << "Віднімання: ";
    v.Display();

    Rational m = r1.mul(r2);
    cout << "Множення: ";
    m.Display();

    Rational d = r1.div(r2);
    cout << "Ділення: ";
    d.Display();

    cout << endl;

    cout << "Порівняння:" << endl;

    if (r1.equal(r2))
    {
        cout << "Дріб 1 дорівнює дробу 2." << endl;
    }
    else
    {
        cout << "Дріб 1 не дорівнює дробу 2." << endl;
    }

    if (r1.greater(r2))
    {
        cout << "Дріб 1 більший за дріб 2." << endl;
    }
    else
    {
        cout << "Дріб 1 не більший за дріб 2." << endl;
    }

    if (r1.less(r2))
    {
        cout << "Дріб 1 менший за дріб 2." << endl;
    }
    else
    {
        cout << "Дріб 1 не менший за дріб 2." << endl;
    }

    return 0;
}