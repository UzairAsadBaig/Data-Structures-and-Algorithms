#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int fibonacci(int term)
{
    if (term == 1 || term == 2)
        return 1;

    return fibonacci(term - 1) + fibonacci(term - 2);
}

int main()
{
    cout << fibonacci(5);
}