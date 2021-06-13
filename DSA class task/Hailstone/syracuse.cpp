#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void syracuse(int n)
{

    if (n != 1)
    {
        cout << n << endl;
        n % 2 == 0 ? syracuse(n / 2) : syracuse((3 * n) + 1);
    }
    else
    {
        cout << 1;
    }
}

int main()
{
    syracuse(17);
}
