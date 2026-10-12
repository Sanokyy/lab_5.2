
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double S(double x, double eps, int& n);
double A(double x, int n, double a);

int main()
{
    double xp, xk, dx, eps;
    int n;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    if (dx <= 0 || xp > xk || eps <= 0) {
        cout << "Incorrect input!" << endl;
        return 1;
    }

    cout << fixed << setprecision(6);
    cout << "---------------------------------------------" << endl;
    cout << setw(10) << "x"
        << setw(12) << "exp(x*x)"
        << setw(12) << "S"
        << setw(8) << "n" << endl;
    cout << "---------------------------------------------" << endl;

    for (double x = xp; x <= xk + dx / 1000; x += dx)
    {
        double s = S(x, eps, n);

        cout << setw(10) << x
            << setw(12) << exp(x * x)
            << setw(12) << s
            << setw(8) << n << endl;
    }

    return 0;
}

double S(double x, double eps, int& n)
{
    double a = 1;
    double s = a;
    n = 1;

    while (true)
    {
        a = A(x, n, a);

        if (abs(a) < eps)
            break;

        s += a;
        n++;
    }
    return s;
}

double A(double x, int n, double a)
{
    return a * x * x / n;
}
