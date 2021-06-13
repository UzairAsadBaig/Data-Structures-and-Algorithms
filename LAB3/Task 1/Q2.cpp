#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

double sumover2(int n)
{
    if (n == 1)
    {
        return 1.0;
    }

    return sumover2(n - 1) / n;
}

int main()
{
    cout << "Enter a value for sumover2 function\n";
    int n;
    cin >> n;
    cout << sumover2(n);
}