#include <iostream>
#include "N_Rational.h"
using namespace std;

int main()
{

    /*
    Implemente um programa que leia dois
    números racionais pela linha de comando
    e imprima o resultado da soma, da
    subtração e da divisão destes dois
    números. Os resultados devem estar na
    forma simplificada.
    */

    int d1, n1, d2, n2;

    cout << "Numerator value for the fisrt rational: " << endl;
    cin >> n1;
    cout << "Denominator value for the fisrt rational: " << endl;
    cin >> d1;

    cout << "Numerator value for the secont rational: " << endl;
    cin >> n2;
    cout << "Denominator value for the secont rational: " << endl;
    cin >> d2;

    N_Rational *r1, *r2, *result;

    r1 = create_rational();
    r2 = create_rational();
    result = create_rational();

    assign_rational(r1, n1, d1);
    assign_rational(r2, n2, d2);

    if (sum_rational(r1, r2, result) == 0) {
        simp_rational(result);
        cout << "Sum result: " << endl;
        printf("Numerator: %d. Denominator: %d\n", result->numerator, result->denominator);
    } else {
        cout << "Sum rror!" << endl;
    }

    if (sub_rational(r1, r2, result) == 0) {
        simp_rational(result);
        cout << "Sum result: " << endl;
        printf("Numerator: %d. Denominator: %d\n", result->numerator, result->denominator);
    } else {
        cout << "Sub error!" << endl;
    }
    
    if (div_rational(r1, r2, result) == 0) {
        simp_rational(result);
        cout << "Div result: " << endl;
        printf("Numerator: %d. Denominator: %d\n", result->numerator, result->denominator);
    } else {
        cout << "Div error!" << endl;
    }

    return 0;
}