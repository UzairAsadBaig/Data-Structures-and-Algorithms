#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int maxNumber(int a[], int n)
{
    if (n == 1)
    {
        return a[0];
    }
    int max = maxNumber(a, n - 1);
    return a[n - 1] > max ? a[n - 1] : max;
}

int main()
{

    int a[10] = {33, 21, 3, 114, 5, 16, 7, 8, 9, 10};
    cout << maxNumber(a, sizeof(a) / sizeof(a[0]));
}