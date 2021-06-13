#include <iostream>

using namespace std;

void move(int count, char start, char finish, char temp)
{
	if (count > 0)
	{
		move(count - 1, start, temp, finish);
		cout << "Move disk " << count << " from " << start << " to " << finish << "." << endl;
		move(count - 1, temp, finish, start);
	}
}

int main()
{
	int disks;
	cout << "Please enter count of disks: ";
	cin >> disks;

	move(disks, 'A', 'C', 'B');

	return 0;
}
