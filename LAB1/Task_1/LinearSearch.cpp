// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int search(int arr[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
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

	time(&t1);						//Again using variable t1
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
