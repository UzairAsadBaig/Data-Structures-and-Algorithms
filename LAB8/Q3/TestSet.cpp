#include <iostream>
#include <string>

#include "Set.h"

using namespace std;

int main()
{
	Set<int> s;

	s.add(1);
	s.add(2);
	s.add(3);
	s.add(4);

	Set<int> t;

	t.add(3);
	t.add(5);
	t.add(6);
	t.add(7);
	t.add(8);

	Set<int> U;

	U.add(1);
	U.add(2);
	U.add(3);
	U.add(4);
	U.add(5);
	U.add(6);
	U.add(7);
	U.add(8);
	U.add(9);
	U.add(10);

	cout << "Set T :  ";
	t.show();
	cout << endl;

	cout << "Set S :  ";
	s.show();
	cout << endl;

	cout << "\nT U S :\n";
	Set<int> TUS = t.setUnion(s);
	TUS.show();
	cout << endl;

	cout << "\nS U T :\n";
	Set<int> SUT = t.setUnion(s);
	SUT.show();
	cout << endl;

	cout << "\nSet S U T == T U S : " << (TUS == SUT) << endl;

	cout << "\nIntersection of T and S is :\n";
	t.setIntersection(s).show();
	cout << endl;
	cout << endl;

	cout << "Set U :  ";
	s.show();
	cout << endl;

	cout << "\n(Using complement method) s' :\n";
	U.setComplement(s).show();
	cout << endl;
	cout << endl;

	cout << "\n(Using - operator) t-s :\n";
	(t - s).show();
	cout << endl;
	cout << endl;

	return 0;
}