#ifndef Set__ADT__Header
#define Set__ADT__Header

template <typename Object>
class SetADT
{
public:
	virtual void add(const Object &) = 0;
	virtual void show() const = 0;
	virtual bool isMember(const Object &) const = 0;
	virtual void remove(const Object &) = 0;
	virtual void replace(const Object &, const Object &) = 0;
	virtual bool isEmpty() const = 0;
	virtual long size() const = 0;
};
#endif //Set__ADT__Header