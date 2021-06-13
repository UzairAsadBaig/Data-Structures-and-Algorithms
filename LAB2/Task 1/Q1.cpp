#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

// iterattive logic (loops)

int factorialIterative(int n)
{
    int f = 1;
    int j = 1;

    while (j <= n)
    {
        f = f * j;
        j = j + 1;
    }

    return f;
}

// recursive logic (function calls itself)

int factorialRecursion(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorialRecursion(n - 1);
}

int main()
{
    time_t t1, t2;
    int number;
    srand(time(0));
    cout << "Input the number\n";
    cin >> number;
    time(&t1);
    cout << "Factorial using recursion " << factorialRecursion(number) << endl;
    time(&t2);
    cout << "Time taken by recursion function " << t2 - t1 << endl;
    t1 = 0;
    t2 = 0;
    time(&t1);
    cout << "Factorial using iteration " << factorialIterative(number) << endl;
    time(&t2);
    cout << "Time taken by iteration function " << t2 - t1 << endl;
}
