#include <iostream>
#include <cmath>

#ifndef PI
#define PI 3.14159265358979323846
#endif

double calcAtan(double* x, int* N_korakov)
{
    double vsota = 0.0;
    double argument = *x;
    int N = *N_korakov;

    for (int n = 0; n < N; n++)
    {
        double clen;
        clen = pow(-1.0, n) * pow(argument, 2 * n + 1) / (2 * n + 1);
        vsota = vsota + clen;
    }

    return vsota;
}

double integrand(double x, int* stevilo_korakov)
{
    double argument;
    double vrednost;

    argument = x / 2.0;
    vrednost = exp(3.0 * x) * calcAtan(&argument, stevilo_korakov);

    return vrednost;
}

int main()
{
  
    double zacetek = 0.0;
    double konec = PI / 4.0;

    int stevilo_trapezov = 1000;
    int stevilo_korakov = 500;

    double korak;
    double integral = 0.0;

    korak = (konec - zacetek) / stevilo_trapezov;


    integral = integral + integrand(zacetek, &stevilo_korakov);

 
    for (int i = 1; i < stevilo_trapezov; i++)
    {
        double x;
        x = zacetek + i * korak;
        integral = integral + 2.0 * integrand(x, &stevilo_korakov);
    }

    integral = integral + integrand(konec, &stevilo_korakov);

 
    integral = integral * korak / 2.0;

    std::cout << "Priblizna vrednost integrala je: "
        << integral << std::endl;

    return 0;

}
