#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> number;
    for (int i = 0; i < 10; i++)
    {
        number.emplace_back(rand());
    }
    for (list<int>::iterator i = number.begin(); i != number.end(); i++)
    {
        if (*i == 15724)
            cout << *i << endl;
    }
}