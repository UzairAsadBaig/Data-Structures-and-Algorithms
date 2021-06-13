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

int nchoosek(int n, int k)
{
    if ((n == n && k == n) || (n == n && k == 0))
    {
        return 1;
    }

    return nchoosek(n - 1, k - 1) + (factorial(n - 1) / (factorial(k) * factorial((n - 1) - k)));
}

int main()
{
    cout << nchoosek(7, 3) << endl;
    cout << nchoosek(9, 5) << endl;
    cout << nchoosek(14, 12) << endl;
}