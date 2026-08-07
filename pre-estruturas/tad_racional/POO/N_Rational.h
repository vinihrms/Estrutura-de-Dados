class N_Rational
{
private:
    int numerator;
    int denominator;

public:
    // constructor
    N_Rational(int n = 0, int d = 1);

    // destructor
    ~N_Rational();

    // assign N_Rational
    int assign_rational(int n, int d);

    // access N_Rational
    int access_rational(int n, int d);

    // sum N_Rational.
    int sum_rational(const N_Rational *r2, N_Rational *result) const;

    // subtact N_Rational.
    int sub_rational(const N_Rational *r2, N_Rational *result) const;

    // mult N_Rational.
    int mult_rational(const N_Rational *r2, N_Rational *result) const;

    // divide N_Rational.
    int div_rational(const N_Rational *r2, N_Rational *result) const;

    // simpliy
    int simp_rational();

    // get
    int get_numerator();
    int get_denominator();
};
