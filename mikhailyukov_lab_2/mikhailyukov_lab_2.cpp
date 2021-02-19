#include <iostream>
#include <cmath>
#define epsilon 0.0000001
using namespace std;

//данная программа считает сумму ряда вида: 1 - x^2 / 3! + x^4 / 5! - ... для введённого x и указанной границы epsilon

double get_number();
double calculate_series_sum(const double x, int* summands_count);

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "укажите число x: ";
    const double x = get_number();
    
    int summands_count = 0;
    const double series_sum = calculate_series_sum(x, &summands_count);

    cout << "сумма ряда для указанного числа x: " << series_sum << ", элементов в посчитанной сумме: " << summands_count;

    return 0;
}


double calculate_series_sum(const double x, int* summands_count)
{
    double summand = 1;
    double series_sum = 0;
    int d = 1;
    while (fabs(summand) > epsilon) {
        series_sum += summand;
        *summands_count += 1;
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