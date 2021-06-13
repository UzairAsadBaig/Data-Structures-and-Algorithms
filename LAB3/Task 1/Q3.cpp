#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void printOctal(int n)
{
    if (n < 8)
    {
        cout << n;
        return;
    }
    printOctal(n / 8);
    cout << n % 8;
}

int main()
{
    cout << "Enter a value to print its Octal value\n";
    int n;
    cin >> n;
    printOctal(n);
}