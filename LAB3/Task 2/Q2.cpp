#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// Auxiliary
double c(int x, int n, unsigned long long int p, long double r)
{
    if (n == 0)
    {
        return 1;
    }

    return c(x, n - 1, (p / n), (r / x)) + (r / p);
}

//I have fixed it upto 20th term of sequences
//Wrapper function
double computeEPowerX(int x)
{
    unsigned long long int p = 1;
    for (int i = 1; i <= 20; i++)
    {
        p = p * i;
    }
    long double r = 1;
    for (int i = 0; i < 20; i++)
    {
        r = r * x;
    }
    return c(x, 20, p, r);
}

int main()
{
    cout << "Enter a value of x to compute e power x\n";
    int x;
    cin >> x;
    cout << computeEPowerX(x);
}