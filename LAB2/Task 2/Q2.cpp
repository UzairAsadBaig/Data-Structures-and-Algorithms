#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

double avg(float arr[], unsigned int index, unsigned int size)
{
    if (index == 0)
    {
        return arr[0] / double(size);
    }
    return avg(arr, index - 1, size) + (arr[index] / double(size));
}

template <int N> //I have used template so that array is not decayed even if it passed as a pointer.This will help me find its size.
double average(float (&arr)[N])
{
    int size = sizeof(arr) / sizeof(arr[0]);
    return avg(arr, size - 1, size);
}

int main()
{
    float a[] = {1.5, 2.3, 3.5, 4.8, 5.9};
    cout << average(a) << endl;
}