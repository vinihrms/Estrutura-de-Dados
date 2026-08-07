#include <stdlib.h>
#include <math.h>
#include "N_Rational.h"



N_Rational *create_rational()
{
    N_Rational *r = (N_Rational *)malloc(sizeof(N_Rational));

    if (r != NULL)
    {
        return r;
    }
    else
    {
        return NULL;
    }
};

void free_rational(N_Rational *r)
{
    free(r);
}

int assign_rational(N_Rational *r, int n, int d)
{
    if (r != NULL)
    {
        if (d != 0)
        {
            r->numerator = n;
            r->denominator = d;
            return 0;
        }
    }
    else
    {
        return 1;
    }
    return 1;
}

int access_rational(N_Rational *r, int n, int d)
{
    if (r != NULL)
    {
        if (r->numerator == n && r->denominator == d)
        {
            return 0;
        }
    }
    else
    {
        return 1;
    }
    return 1;
}

int sum_rational(N_Rational *r1, N_Rational *r2, N_Rational *result)
{
    if (r1 != NULL && r2 != NULL && result != NULL)
    {
        result->numerator = (r1->numerator * r2->denominator) + (r1->denominator * r2->numerator);
        result->denominator = (r1->denominator * r2->denominator);
        return 0;
    }
    else
    {
        return 1;
    }
}

int sub_rational(N_Rational *r1, N_Rational *r2, N_Rational *result)
{
    if (r1 != NULL && r2 != NULL && result != NULL)
    {
        result->numerator = (r1->numerator * r2->denominator) - (r1->denominator * r2->numerator);
        result->denominator = (r1->denominator * r2->denominator);
        return 0;
    }
    else
    {
        return 1;
    }
}

int mult_rational(N_Rational *r1, N_Rational *r2, N_Rational *result)
{
    if (r1 != NULL && r2 != NULL && result != NULL)
    {
        result->numerator = (r1->numerator * r2->numerator);
        result->denominator = (r1->denominator * r2->denominator);
        return 0;
    }
    else
    {
        return 1;
    }
}

int div_rational(N_Rational *r1, N_Rational *r2, N_Rational *result)
{
    if (r1 != NULL && r2 != NULL && result != NULL)
    {
        result->numerator = (r1->numerator * r2->denominator);
        result->denominator = (r1->denominator * r2->numerator);
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

int simp_rational(N_Rational *r)
{
    int divisor = mdc(abs(r->numerator), abs(r->denominator));
    r->numerator /= divisor;
    r->denominator /= divisor;

    if (r->denominator < 0)
    {
        r->numerator = -r->numerator;
        r->denominator = -r->denominator;
    }

    return 0;
}


