#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

double sumover(unsigned int x)
{
    if (x == 1)
    {
        return 1;
    }
    return sumover(x - 1) + (1 / double(x));
}

int main()
{
    unsigned int number;
    cout << "Enter the number" << endl;
    cin >> number;
    cout << "The result of the sumover function is " << sumover(number) << endl;
}