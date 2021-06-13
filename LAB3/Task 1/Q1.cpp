#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int firstN(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return firstN(n - 1) + n;
}

int main()
{
    cout << "Enter the value of N to find the sum of first N values\n";
    int n;
    cin >> n;
    cout << firstN(n);
}