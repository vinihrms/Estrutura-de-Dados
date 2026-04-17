#include <stdlib.h>
#include <math.h>
#include "N_Rational.h"

N_Rational::N_Rational(int n, int d)
{
    numerator = n;
    denominator = d;
}

N_Rational::~N_Rational()
{
}

int N_Rational::assign_rational(int n, int d)
{
    if (d != 0)
    {
        numerator = n;
        denominator = d;
        return 0;
    }
    return 1;
}

int N_Rational::access_rational(int n, int d)
{
    if (numerator == n && denominator == d)
    {
        return 0;
    }
    else
        return 1;
}

int N_Rational::sum_rational(const N_Rational *r2, N_Rational *result) const
{
    if (r2 != NULL && result != NULL)
    {
        result->numerator = numerator * r2->denominator + denominator * r2->numerator;
        result->denominator = denominator * r2->denominator;
        return 0;
    }
    else
        return 1;
}

int N_Rational::sub_rational(const N_Rational *r2, N_Rational *result) const
{
    if (r2 != NULL && result != NULL)
    {
        result->numerator = (numerator * r2->denominator) - (denominator * r2->numerator);
        result->denominator = (denominator * r2->denominator);
        return 0;
    }
    else
        return 1;
}

int N_Rational::mult_rational(const N_Rational *r2, N_Rational *result) const
{
    if (r2 != NULL && result != NULL)
    {
        result->numerator = (numerator * r2->numerator);
        result->denominator = (denominator * r2->denominator);
        return 0;
    }
    else
    {
        return 1;
    }
}

int N_Rational::div_rational(const N_Rational *r2, N_Rational *result) const
{
    if (r2 != NULL && result != NULL)
    {
        if (r2->numerator == 0)
        {
            return 1;
        }
        result->numerator = (numerator * r2->denominator);
        result->denominator = (denominator * r2->numerator);
        return 0;
    }
    else
    {
        return 1;
    }
}

int mdc(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int N_Rational::simp_rational()
{
    int divisor = mdc(abs(numerator), abs(denominator));
    numerator /= divisor;
    denominator /= divisor;

    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    return 0;
}

int N_Rational::get_numerator()
{
    return numerator;
}

int N_Rational::get_denominator()
{
    return denominator;
}
