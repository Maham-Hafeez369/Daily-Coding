#include <iostream>
#include <string>
#include <array>
#include <cmath>

using namespace std;

// understand the following code and then
// code the rest of the Polynomial related
// functions

// Type Polynomial is just an array of 10 ints
// its indices consides with the powers of
// Polynomial's variable, and values are the
// coefficient
typedef array<int, 10> Polynomial;

void showPolynomial(Polynomial p)
{
    int j = 9;
    while (p[j] == 0 && j >= 0) // skip extra leading zeros
    {
        j = j - 1;
    }
    while (j >= 0)
    {
        cout << ' ';
        if (p[j] >= 0)
        {
            cout << '+';
        }
        cout << p[j] << 'x' << '^' << j;
        j = j - 1;
    }

    return;
}
Polynomial addPolynomials(Polynomial a, Polynomial b)
{
    Polynomial c;
    for (int i = 0; i < 10; i++)
    {
        c[i] = a[i] + b[i];
    }
    return c;
};
int evaluatePolynomial(Polynomial a, int x)
{
    int result;
    for (int i = 0; i < 10; i++)
    {
        result += a[i] * pow(x, i);
    }
    return result;
};

int main()
{
    Polynomial p1{-7, 1, -5, 0, 3, 0, 0, 0, 0, 0};
    Polynomial p2{1, 2, 3}; // rest of indices will become 0 by default

    cout << "Polynomial p1 is: ";
    showPolynomial(p1);
    cout << endl;
    cout << "Polynomial p2 is: ";
    showPolynomial(p2);
    cout << endl;
    cout << "Addition of polynomial: ";
    showPolynomial(addPolynomials(p1, p2));
    cout << endl;
    cout << " Evaluation of polynomial: ";
    cout << "The evaluation of ploynomial 1 with 4 is" << evaluatePolynomial(p1, 4);
    cout << endl;

    return 0;
}

// this implementation can be improved many folds
