#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct location{
    int x;
    int y

    isValid()
}

void s(int n, string name)
{
    fstream fout(name);
    if (n + 1 <= 100 && n + 101 <= 1000 && n - 1 >= -1)
    {

        fout.seekg(n, ios::beg);
        char a = fout.get();
        // cout << a << "oo gpro";s
        if (a == 'R')
        {
            return;
        }
        else if (a == ' ')
        {
            fout.seekp(n, ios::beg);
            fout << 'U';
            s(n + 1, name);
            s(n - 1, name);
            s(n + 100, name);
            s(n - 100, name);
        }
        else if (a == '*' || a == 'S')
        {
            s(n + 1, name);
            s(n - 1, name);
            s(n + 100, name);
            s(n - 100, name);
        }
    }
}

void solveMaze(string name)
{
    s(0, name);
    cout << "hi";
}

int main()
{

    cout << "Enter the name of the file" << endl;
    string name;
    cin >> name;
    solveMaze(name);
}