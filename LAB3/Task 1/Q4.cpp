#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int GCD(int a, int b)
{
    if (a == b)
    {
        return a;
    }
    //I am using Euclid's algorithm
    return a > b ? GCD(a - b, b) : GCD(a, b - a);
}

int main()
{
    cout << "Enter the first number\n";
    int a;
    cin >> a;
    cout << "Enter the Second number\n";
    int b;
    cin >> b;
    cout << "The result of GCD is " << GCD(a, b) << endl;
}