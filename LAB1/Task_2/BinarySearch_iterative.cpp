// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string checkDataType(string name)
{
    string rtype;
    ifstream rfile(name);
    getline(rfile, rtype);
    if (rtype[0] == '"')
    {
        return "string";
    }
    else
    {
        return "int";
    }
}
unsigned int maxSize(string name)
{
    string line;
    ifstream rfile(name);
    unsigned int count = 0;
    while (!rfile.eof())
    {
        getline(rfile, line, '"');
        count++;
    }
    return count;
}
unsigned long long int *readDataFile()
{
    cout << "Enter the name of csv file without extention\n";
    string name;
    cin >> name;
    name += ".csv";
    string dataType = checkDataType(name);
    unsigned int MaxSize = maxSize(name);
    unsigned long long int *arr = new unsigned long long int[MaxSize]; //it will extend according to requirement
    ifstream rfile(name);
    //Parsing
    string line;
    string num;
    stringstream ss;
    stringstream parsedSs;
    unsigned int count = 0;
    while (!rfile.eof())
    {

        if (dataType == "string")
        {
            getline(rfile, line);

            ss << line;

            while (!ss.eof())
            {
                getline(ss, num, '"');
                if (num[0] == ',' || num[0] == '\0')
                {
                    continue;
                }

                for (int i = 0; i < num.length(); i++)
                {
                    if (num[i] != ',')
                    {
                        parsedSs << num[i];
                    }
                }
                parsedSs >> arr[count];

                parsedSs.clear();
                count++;
                if (count == MaxSize)
                    break;
            }
            ss.clear();
        }
        else
        {
            getline(rfile, line);
            ss << line;
            while (!ss.eof())
            {

                getline(ss, num, ',');
                arr[count] = stoi(num);
                count++;
            }
            ss.clear();
        }
    }
    arr[-1] = count; //Storing the size of the array on -1th
    return arr;
}

// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearchIter(unsigned long long int arr[], unsigned int l, unsigned int r, unsigned long long int x)
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
int search(unsigned long long int arr[], unsigned int n, unsigned long long int x)
{
    return binarySearchIter(arr, 0, n - 1, x);
}

// Driver code
int main(void)
{
    time_t t1, t2;
    srand(time(0));

    unsigned long long int *arr = readDataFile();
    unsigned long long int x;
    cout << "Enter the number to be searched\n";
    cin >> x;
    unsigned int n = arr[-1]; //Size of array is stored on -1th index

    // sort(arr, arr + n);

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
    delete[] arr;
    return 0;
}
