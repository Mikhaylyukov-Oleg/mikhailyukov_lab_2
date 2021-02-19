#include <iostream>
#include <cmath>
#define elements_count 200
using namespace std;

//данная программа считает сумму ряда вида: 1 - x^2 / 3! + x^4 / 5! - ... для введённого x для elements_count элементов последовательности

double get_number();
double calculate_series_sum(const double x);

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "укажите число x: ";
    const double x = get_number();
    
    const double series_sum = calculate_series_sum(x);

    cout << "сумма " << elements_count << " элементов ряда для указанного числа x: " << series_sum;

    return 0;
}


double calculate_series_sum(const double x)
{
    double summand = 1;
    double series_sum = 0;
    int d = 1;
    for (int i = 0; i < elements_count; i++) {
        series_sum += summand;
        d += 2;
        summand *= -1 * x * x / d / (d - 1);
    }
    return series_sum;
}

double get_number()
{
    while (true)
    {
        double number;
        cin >> number;
        if (cin.fail())
        {
            cout << "ошибка: вы ввели не число\n";
            cout << "введите данные снова: ";
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else {
            cin.ignore(32767, '\n');
            return number;
        }
    }
}