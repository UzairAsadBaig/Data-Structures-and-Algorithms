// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearchIter(int arr[], int l, int r, int x)
{
    int i = 0;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}
int search(int arr[], int n, int x)
{
    return binarySearchIter(arr, 0, n - 1, x);
}

// Driver code
int main(void)
{
    time_t t1, t2;
    srand(time(0));

    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + (n - 1));

    time(&t1);                      //Again using variable t1
    int result = search(arr, n, x); // Function call
    time(&t2);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;

    cout << endl;
    double search_time = t2 - t1;
    cout << "Time taken by Search: " << search_time << " seconds" << endl
         << endl;

    return 0;
}
