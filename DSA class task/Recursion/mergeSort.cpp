#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void combine(int a[], int s, int m, int e)
{
    int *buffer = new int[e + 1];

    int k = s;
    while (k <= e)
    {
        buffer[k] = a[k];
        k = k + 1;
    }

    int i = s;
    int j = m + 1;
    k = s;
    while (i <= m && j <= e)
    {
        if (buffer[i] <= buffer[j])
        {
            a[k] = buffer[i];
            i = i + 1;
        }
        else
        {
            a[k] = buffer[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i <= m)
    {
        a[k] = buffer[i];
        i = i + 1;
        k = k + 1;
    }
    while (j <= e)
    {
        a[k] = buffer[j];
        j = j + 1;
        k = k + 1;
    }

    delete[] buffer;
}

void ms(int arr[], int start, int end)
{
    if (start == end)
    {
        return;
    }
    int m = (start + end) / 2;
    ms(arr, start, m);
    ms(arr, m + 1, end);
    combine(arr, start, m, end);
}

void mergeSort(int arr[], int size)
{
    ms(arr, 0, size - 1);
}

void fillArray(int a[], int n)
{
    int i = 0;
    while (i < n)
    {
        a[i] = rand() % 9 + rand() % 9;
        i = i + 1;
    }
}

int main()
{
    //   ::count = 0; // global variable
    int a[10];
    fillArray(a, sizeof(a) / sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << endl;
    }

    cout << endl
         << "-----------------------------------------------------------" << endl;

    mergeSort(a, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << endl;
    }
}