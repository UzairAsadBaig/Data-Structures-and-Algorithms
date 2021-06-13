#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void printBin(int n)
{
    if (n < 2)
    {
        if (n % 2 == 0)
            cout << "0";
        else
            cout << "1";

        return;
    }

    printBin(n / 2);
    if (n % 2 == 0)
        cout << "0";
    else
        cout << "1";
}

int main()
{
    for (int i = 0; i < 50; i++)
    {
        printBin(i);
        cout << endl;
    }
}