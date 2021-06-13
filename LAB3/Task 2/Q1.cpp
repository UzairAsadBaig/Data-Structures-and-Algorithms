#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

unsigned long long int factorial(int num)
{
    if (num == 1)
    {
        return 1;
    }

    return num * factorial(num - 1);
}

// Auxiliary
double c(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    return c(x, n - 1) + (pow(x, n) / factorial(n));
}

//I have fixed it upto 20th term of sequences
//Wrapper function
double computeEPowerX(int x)
{
    return c(x, 20);
}

int main()
{
    cout << "Enter a value of x to compute e power x\n";
    int x;
    cin >> x;
    cout << computeEPowerX(x);
}