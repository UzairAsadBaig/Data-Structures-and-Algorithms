#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int count = 0;

void swap(int arr[], int a, int b)
{
    ::count++;
    int temp = arr[a];
    ::count++;
    arr[a] = arr[b];
    ::count++;
    arr[b] = temp;
    ::count++;
    return;
}

void s(int arr[], int size, int start)
{
    ::count++;
    if (start >= size)
    {
        ::count++;
        return;
    }
    ::count++;
    s(arr, 10, start + 1);
    ::count++;
    int min = start;
    ::count++;
    for (int i = start; i < size; i++)
    {
        ::count++;
        if (arr[i] < arr[min])
        {
            ::count++;
            min = i;
        }
    }
    ::count++;
    swap(arr, min, start);
}

void selectSort(int arr[], int size)
{
    ::count++;
    for (int i = size; i > 0; i--)
    {
        ::count++;
        s(arr, size, 0);
    }
}

void fillArray(int a[], int n)
{
    int i = 0;
    while (i < n)
    {
        a[i] = rand() % 99999 + rand() % 99;
        i = i + 1;
    }
}

int main()
{
    ::count = 0; // global variable
    int a[1000];
    fillArray(a, sizeof(a) / sizeof(int));
    selectSort(a, 1000);

    cout << "Steps taken during sorting are " << ::count << endl;
}