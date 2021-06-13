#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int fibonacci1Recursion(int term)
{
    if (term == 1 || term == 2)
        return 1;

    return fibonacci1Recursion(term - 1) + fibonacci1Recursion(term - 2);
}

double f(int n, int a[])
{
    if (a[n - 1] == 0)
    {
        if (n == 1 || n == 2)
            a[n - 1] = 1;
        else
            a[n - 1] = f(n - 1, a) + f(n - 2, a);
    }
    return a[n - 1];
}

int fibonacci2Recursion(int n)
{
    int tmp[n];
    for (int i = 0; i < n; i++)
    {
        tmp[i] = 0;
    }

    return f(n, tmp);
}

int fibonacciIterative(int num)
{
    int x = 0, y = 1, z = 0;
    for (int i = 0; i < num; i++)
    {
        z = x + y;
        x = y;
        y = z;
    }
    return x;
}

int main()
{
    time_t t1, t2;
    int number;
    srand(time(0));
    cout << "Input the number\n";
    cin >> number;
    // time(&t1);
    // cout << "Fibonacci using recursion " << fibonacci1Recursion(number) << endl;
    // time(&t2);
    // cout << "Time taken by recursion function " << t2 - t1 << endl;

    t1 = 0;
    t2 = 0;
    time(&t1);
    cout << "Fibonacci using recursion-2   " << fibonacci2Recursion(number) << endl;
    time(&t2);
    cout << "Time taken by recursion-2 function " << t2 - t1 << endl;

    t1 = 0;
    t2 = 0;
    time(&t1);
    cout << "Fibonacci using iteration " << fibonacciIterative(number) << endl;
    time(&t2);
    cout << "Time taken by iteration function " << t2 - t1 << endl;
}