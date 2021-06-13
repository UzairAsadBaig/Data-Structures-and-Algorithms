#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

string FibonacciString(int n)
{
    if (n == 0)
    {
        return "a";
    }
    else if (n == 1)
    {
        return "bc";
    }

    return FibonacciString(n - 2) + FibonacciString(n - 1);
}

int main()
{
    cout << "Enter the value of N to find the Nth fibonacci term\n";
    int n;
    cin >> n;
    cout << FibonacciString(n);
}