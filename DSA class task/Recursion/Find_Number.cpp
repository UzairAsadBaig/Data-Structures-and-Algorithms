#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int findNumber(int a[], int n, int num)
{
    cout << "Index:" << (n / 2) - 1 << endl;
    cout << "Value:" << a[(n / 2) - 1] << endl;
    if (a[n / 2 - 1] == num)
    {
        return (n / 2) - 1;
    }

    return (a[(n / 2) - 1] > num) ? findNumber(a, n + (10 - (n - 1)) / 2, num) : findNumber(a, n / 2, num);
    return findNumber(a, n * 2, num);
    // return findNumber(a, n + ((n - 1) / 2), num);
}

int main()
{
    int a[10] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 92};
    cout << findNumber(a, 10, 0);
}