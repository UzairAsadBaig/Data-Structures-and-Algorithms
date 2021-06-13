#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int f(int term, int lastVal)
{
    if (term == 1 || term == 2)
        return 1;

    return fibonacci(term - 1) + fibonacci(term - 2);
}

int fibonacci(int term)
{
    return f(term, 0);
}

int main()
{
    cout << endl
         << "Hello" << fibonacci(6);
}