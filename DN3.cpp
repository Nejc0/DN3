#include <iostream>
#include <cmath>

#ifndef Pi
#define Pi 3.14159265358979323846
#endif


double calcAtan(double* x, int* N_steps)
{
    double value = 0.0;
    double xx = *x;
    int N = *N_steps;

    for (int n = 0; n < N; ++n)
    {
        double term =
            std::pow(-1.0, n) * std::pow(xx, 2 * n + 1) / (2 * n + 1);
        value += term;
    }
    return value;
}


double f(double x, int* N_steps)
{
    double arg = x / 2.0;               
    double atan_val = calcAtan(&arg, N_steps);
    return std::exp(3.0 * x) * atan_val;
}

int main()
{
    const double a = 0.0;
    const double b = Pi / 4.0;

    const int n = 1000;       
    const int N_steps = 50;    

    double dx = (b - a) / n;
    double integral = 0.0;

  
    integral += f(a, (int*)&N_steps);

    for (int i = 1; i < n; ++i)
    {
        double x = a + i * dx;
        integral += 2.0 * f(x, (int*)&N_steps);
    }

    integral += f(b, (int*)&N_steps);
    integral *= dx / 2.0;

    std::cout << "Priblizna vrednost integrala: "
        << integral << std::endl;

    return 0;
}
