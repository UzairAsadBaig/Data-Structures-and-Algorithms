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

class itemList
{
private:
    int arraySize;
    int listSize;
    item *array;

public:
    int getArraySize() const
    {
        return this->arraySize;
    }
    void setArraySize(int a)
    {
        this->arraySize = a;
    }
    int getListSize() const
    {
        return this->listSize;
    }
    void setListSize(int a)
    {
        this->listSize = a;
    }
    itemList(int count)
    {
        this->setArraySize(pow(2, count));
        this->setListSize(0);
        this->array = new item[this->getArraySize()];
    }

    void append(item a)
    {

        array[this->getListSize()] = a;
        listSize++;
    }
    void printWeightPattern(item a[], int count, int w)
    {
        item reqItem(0, 0);
        int index = 0;
        stringstream binary;
        char random;
        for (int i = 0; i < this->getListSize(); i++)
        {
            if (array[i].getWeight() <= w && array[i].getValue() > reqItem.getValue())
            {
                reqItem = array[i];
                index = i;
            }
        }
        while (index != 0)
        {
            binary << index % 2;
            index = index / 2;
        }
        cout << "Maximum Value: " << reqItem.getValue() << endl
             << "Set: {";
        for (int i = 0; i < count; i++)
        {
            binary >> random;
            if (random == 49)
                cout << i + 1 << ",";
        }
        cout << "\b}";
    }
};

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

    itemList soda(count);
    stringstream binary;
    int num;
    int c;
    for (int i = 0; i < pow(2, count); i++)
    {
        c = 0;
        num = i;
        while (num != 0)
        {
            binary << num % 2;
            // cout << num % 2;
            num = num / 2;
            c++;
        }
        for (int i = c; i < count; i++)
        {
            binary << '0';
            // cout << 0;
        }
    }

    item sum;
    char random;
    for (size_t i = 0; i < pow(2, count); i++)
    {
        sum.setVal(0, 0);

        for (int i = 0; i < count; i++)
        {

            binary >> random;
            // cout << random;
            if (random == 49)
            {
                sum = sum + a[i];
            }
        }
        soda.append(sum);
        // cout << endl;
    }
    soda.printWeightPattern(a, count, 15);
}