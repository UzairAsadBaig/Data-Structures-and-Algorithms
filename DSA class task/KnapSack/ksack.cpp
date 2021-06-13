#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class item
{
private:
public:
    double value;
    double weight;

    item()
    {
        this->value = 0;
        this->weight = 0;
    }
    item(int x, int y)
    {
        this->value = x;
        this->weight = y;
    }

    item operator+(item &a)
    {
        item ret;
        ret.value = this->value + a.value;
        ret.weight = this->weight + a.weight;
        return ret;
    }

    void setVal(int x, int y)
    {
        this->value = x;
        this->weight = y;
    }

    friend ostream &operator<<(ostream &sout, item &i)
    {

        // sout << i.value << "," << i.weight;
        sout << i.value;
        return sout;
    }
};

void pat1(int count, int &limIndex, item a[], item sum2D[])
{
    for (int x = 0; x < count; x++)
    {

        for (int j = 0; j < count - x; j++)
        {
            for (int n = count - x - 1; n >= j; n--)
            {

                // cout << a[n];
                sum2D[limIndex] = sum2D[limIndex] + a[n];
            }
            limIndex++;
            // cout << endl;
        }
    }
}
void pat2(int count, int &limIndex, item a[], item sum2D[])
{
    for (int k = 0; k < count; k++)
    {
        int x = 2;
        for (int i = 0; i < count - x - k; i++)
        {
            // cout << a[k];
            for (int j = x + i + k; j < count; j++)
            {
                // cout << a[j];
                sum2D[limIndex] = sum2D[limIndex] + a[j];
            }
            limIndex++;
            // cout << endl;
        }
    }
}
void pat3(int count, int &limIndex, item a[], item sum2D[])
{
    int rcount = count - 1;
    int x = 2;
    for (int k = 0; k < count; k++)
    {
        for (int j = 0; j < count - k - x; j++)
        {
            // cout << a[rcount - k];
            sum2D[limIndex] = sum2D[limIndex] + a[rcount - k];
            for (int i = rcount - x - j - k; i >= 0; i--)
            {
                // cout << a[i];
                sum2D[limIndex] = sum2D[limIndex] + a[i];
            }
            limIndex++;
            // cout << endl;
        }
    }
}

int main()
{
    int count = 9;
    item a[count];
    // a[0].setVal(2, 3);
    // a[1].setVal(3, 5);
    // a[2].setVal(3, 7);
    // a[3].setVal(4, 4);
    // a[4].setVal(4, 3);
    // a[5].setVal(5, 9);
    // a[6].setVal(7, 2);
    // a[7].setVal(8, 11);
    // a[8].setVal(8, 5);
    a[0].setVal(1, 3);
    a[1].setVal(2, 5);
    a[2].setVal(3, 7);
    a[3].setVal(4, 4);
    a[4].setVal(5, 3);
    a[5].setVal(6, 9);
    a[6].setVal(7, 2);
    a[7].setVal(8, 11);
    a[8].setVal(9, 5);

    int lim2D = pow(2, count);
    int limIndex = 0;
    item sum2D[lim2D];

    cout << limIndex;
}