#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int factorial(int num)
{
    if (num == 1)
    {
        return 1;
    }

    return num * factorial(num - 1);
}

int main()
{
    cout << factorial(1) << endl;
    cout << factorial(2) << endl;
    cout << factorial(3) << endl;
    cout << factorial(4) << endl;
    cout << factorial(5) << endl;
}