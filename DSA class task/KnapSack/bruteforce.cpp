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
    double value;
    double weight;

public:
    int getValue()
    {
        return this->value;
    }
    int getWeight()
    {
        return this->weight;
    }
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

        sout << i.value << "," << i.weight;
        // sout << i.value;
        return sout;
    }
};

string getBinary(int num, int diget)
{
    int c = 0;
    string bin = " ";
    stringstream binSs;
    while (num != 0)
    {
        binSs << num % 2;

        // cout << num % 2;
        num = num / 2;
        c++;
    }
    for (int i = c; i < diget; i++)
    {
        bin = bin + "0";
    }
    binSs >> bin;
    return bin;
}

int main()
{
    int count = 9;
    item a[count];
    a[0].setVal(2, 3);
    a[1].setVal(3, 5);
    a[2].setVal(3, 7);
    a[3].setVal(4, 4);
    a[4].setVal(4, 3);
    a[5].setVal(5, 9);
    a[6].setVal(7, 2);
    a[7].setVal(8, 11);
    a[8].setVal(8, 5);

    string pattern = " ";
    string ans = " ";
    item maxItem(0, 0);
    item sum;
    for (int n = 0; n < pow(2, count); n++)
    {
        sum.setVal(0, 0);
        string random = getBinary(n, count);
        pattern = " ";
        for (int i = 0; i < count; i++)
        {

            if (random[i] == '1')
            {
                sum = sum + a[i];
                pattern = pattern + to_string(i + 1) + ",";
            }
        }
        if ((15 >= sum.getWeight()) && (sum.getValue() > maxItem.getValue()))
        {
            maxItem = sum;
            ans = pattern;
        }
    }

    cout << maxItem << endl;
    cout << "{" << ans << "\b"
         << " }";
}