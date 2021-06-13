#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void replace(int **data, const int height, const int width, int sr, int sc, const int bc, const int fc)
{
    //if the number is with in the range and equal to bc then replace
    if ((sr < height) && (sc < width) && (sr >= 0) && (sc >= 0) && data[sr][sc] == bc)
    {

        data[sr][sc] = fc;
        //After replacing search for its neighbours,In my case I have tested 8 neigibours surrounding the number.
        replace(data, height, width, sr, sc - 1, bc, fc);
        replace(data, height, width, sr, sc + 1, bc, fc);
        replace(data, height, width, sr - 1, sc, bc, fc);
        replace(data, height, width, sr + 1, sc, bc, fc);
        replace(data, height, width, sr + 1, sc, bc, fc);
        replace(data, height, width, sr - 1, sc - 1, bc, fc);
        replace(data, height, width, sr + 1, sc + 1, bc, fc);
        replace(data, height, width, sr + 1, sc - 1, bc, fc);
        replace(data, height, width, sr - 1, sc + 1, bc, fc);
    }
    else
        return;
}
int main()
{
    //Making the matrix and loading some pattern of values in it

    int **matrix = new int *[8];
    for (int i = 0; i < 8; i++)
        matrix[i] = new int[7];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            matrix[i][j] = rand() % 10;

            if (i == 5)
                matrix[i][j] = 2;
            if (j == 2)
                matrix[i][j] = 2;
        }
    }
    cout << "Before Replacement" << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;

    //Using the replace funtion to replace all 2 present in the matrix with 9 by starting with 0th row and 2 nd column
    replace(matrix, 8, 7, 0, 2, 2, 9);

    //Printing the result after the replacemnet
    cout << "After Replacement" << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}