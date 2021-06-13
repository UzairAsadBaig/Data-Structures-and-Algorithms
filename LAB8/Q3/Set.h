#ifndef Set__Header
#define Set__Header

#include "SetADT.h"

#define Set_SIZE_DEFAULT 20

template <typename Object>
class Set : public SetADT<Object>
{
protected:
	Object *data;
	long arraySize;
	long setSize;

	void create(int);
	void increaseSize();
	long curIndexOf(const Object &) const;

public:
	Set();
	Set(int);
	~Set();

	void add(const Object &);
	void show() const;
	bool isMember(const Object &) const;
	void remove(const Object &);
	void replace(const Object &, const Object &);
	bool isEmpty() const;
	long size() const;
	bool isFull() const;
	Set<Object> &setUnion(const Set<Object> &);
	Set<Object> &setIntersection(const Set<Object> &);
	Set<Object> &setComplement(const Set<Object> &);
	Set<Object> &operator-(const Set<Object> &);
	bool operator==(const Set<Object> &) const;
};

#include "SetCpp.h"

#endif //Set__Header