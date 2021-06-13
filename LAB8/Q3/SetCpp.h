#include <iostream>
#include <string>
#include "Set.h"

using namespace std;

template <typename Object>
void Set<Object>::create(int sz)
{
	this->data = new Object[sz];
	this->arraySize = sz;
	this->setSize = 0;
}

template <typename Object>
void Set<Object>::increaseSize()
{
	// will be implemented later
}

template <typename Object>
long Set<Object>::curIndexOf(const Object &e) const
{
	for (long k = 0; k < this->setSize; k++)
	{
		if (this->data[k] == e) // == operator must be available for Object type
		{
			return k;
		}
	}
	return -1;
}

template <typename Object>
Set<Object>::Set()
{
	this->create(Set_SIZE_DEFAULT);
}

template <typename Object>
Set<Object>::Set(int sz)
{
	this->create(sz);
}

template <typename Object>
Set<Object>::~Set()
{
	delete[] this->data;
	this->data = NULL;
}

template <typename Object>
void Set<Object>::add(const Object &e)
{
	if (isMember(e))
		return;
	if (this->isFull())
	{
		this->increaseSize();
	}
	if (this->isFull())
	{
		//throw string("Set is full!!");
	}
	this->data[this->setSize] = e;
	this->setSize++;
}

template <typename Object>
void Set<Object>::show() const
{
	cout << "{";
	for (int k = 0; k < this->setSize; k++)
	{
		cout << this->data[k] << ",";
	}
	if (!isEmpty())
		cout << "\b}";
	else
		cout << "}";
}

template <typename Object>
bool Set<Object>::isMember(const Object &e) const
{
	long ci = this->curIndexOf(e);
	return (ci >= 0 && ci < this->arraySize);
}

template <typename Object>
void Set<Object>::remove(const Object &e)
{
	long ci = this->curIndexOf(e);
	this->data[ci] = this->data[--this->setSize];
}

template <typename Object>
void Set<Object>::replace(const Object &oldo, const Object &newo)
{
	long ci = this->curIndexOf(oldo);
	this->data[ci] = newo;
}

template <typename Object>
bool Set<Object>::isEmpty() const
{
	return (this->setSize == 0);
}

template <typename Object>
long Set<Object>::size() const
{
	return this->setSize;
}

template <typename Object>
bool Set<Object>::isFull() const
{
	return (this->setSize == this->arraySize);
}

template <typename Object>
Set<Object> &Set<Object>::setUnion(const Set<Object> &b)
{
	Set<Object> *ret = new Set<Object>();
	for (int i = 0; i < size(); i++)
		ret->add(data[i]);
	for (int i = 0; i < b.size(); i++)
		ret->add(b.data[i]);
	return *ret;
}

template <typename Object>
Set<Object> &Set<Object>::setIntersection(const Set<Object> &b)
{
	Set<Object> *ret = new Set<Object>();
	int i;
	for (i = 0; i < size(); i++)
		if (b.isMember(data[i]))
			ret->add(data[i]);
	return *ret;
}

template <typename Object>
Set<Object> &Set<Object>::setComplement(const Set<Object> &b)
{
	Set<Object> *ret = new Set<Object>();
	int i;
	for (i = 0; i < size(); i++)
		if (!b.isMember(data[i]))
			ret->add(data[i]);
	return *ret;
}
template <typename Object>
Set<Object> &Set<Object>::operator-(const Set<Object> &b)
{
	Set<Object> *ret = new Set<Object>();
	int i;
	for (i = 0; i < size(); i++)
		if (!b.isMember(data[i]))
			ret->add(data[i]);
	return *ret;
}

//This set equality operator will work for unordered sets.

template <typename Object>
bool Set<Object>::operator==(const Set<Object> &b) const
{

	if (size() == b.size())
	{
		for (int i = 0; i < size(); i++)
		{
			if (!b.isMember(data[i]))
				return false;
		}
		return true;
	}
	else
		return true;
}
