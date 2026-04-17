typedef struct N_Rational{
    int numerator;
    int denominator;
} N_Rational;

// create N_Rational
N_Rational *create_rational();

// free N_Rational
void free_rational(N_Rational *r);

// assign N_Rational
int assign_rational(N_Rational *r, int n, int d);

// access N_Rational
int access_rational(N_Rational *r, int n, int d);

// sum N_Rational.
int sum_rational(N_Rational *r1, N_Rational *r2, N_Rational *result);

// subtract N_Rational
int sub_rational(N_Rational *r1, N_Rational *r2, N_Rational *result);

// multiply N_Rational
int mult_rational(N_Rational *r1, N_Rational *r2, N_Rational *result);

// divide N_Rational
int div_rational(N_Rational *r1, N_Rational *r2, N_Rational *result);

// simplify N_Raional
int simp_rational(N_Rational *r);
