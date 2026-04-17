#include <iostream>
#include "N_Rational.h"
using namespace std;

int main()
{

    /*
    Intruction:
    Implemente um programa que leia dois
    números racionais pela linha de comando
    e imprima o resultado da soma, da
    subtração e da divisão destes dois
    números. Os resultados devem estar na
    forma simplificada.
    */

    int n1, d1, n2, d2;

    cout << "Numerator value for the fisrt rational: " << endl;
    cin >> n1;
    cout << "Denominator value for the fisrt rational: " << endl;
    cin >> d1;

    cout << "Numerator value for the secont rational: " << endl;
    cin >> n2;
    cout << "Denominator value for the secont rational: " << endl;
    cin >> d2;

    N_Rational r1(n1, d1);
    N_Rational r2(n2, d2);
    N_Rational result;

    if (r1.sum_rational(&r2, &result) == 0)
    {
        result.simp_rational();
        cout << "Sum result: " << endl;
        cout << "Numerator: " << result.get_numerator() << ". Denominator: " << result.get_denominator() << endl;
    }
    else
    {
        cout << "Sum rror!" << endl;
    }

    if (r1.sub_rational(&r2, &result) == 0)
    {
        result.simp_rational();
        cout << "Sub result: " << endl;
        printf("Numerator: %d. Denominator: %d\n", result.get_numerator(), result.get_denominator());
    }
    else
    {
        cout << "Sub error!" << endl;
    }

    if (r1.div_rational(&r2, &result) == 0)
    {
        result.simp_rational();
        cout << "Div result: " << endl;
        printf("Numerator: %d. Denominator: %d\n", result.get_numerator(), result.get_denominator());
    }
    else
    {
        cout << "Div error!" << endl;
    }

    return 0;
}