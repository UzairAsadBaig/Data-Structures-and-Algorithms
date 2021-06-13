#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename Object>
class List
{
private:
	// The basic doubly linked list node.
	// Nested inside of List, can be public
	// because the Node is itself private
	struct Node
	{
		Object data;
		Node *prev;
		Node *next;

		Node(const Object &d = Object(), Node *p = NULL, Node *n = NULL)
			: data(d), prev(p), next(n)
		{
		}
	};

	int theSize;
	Node *head;
	Node *tail;

	void init()
	{
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}

public:
	class const_iterator
	{
	protected:
		Node *current;

		// Protected helper in const_iterator that returns the object
		// stored at the current position. Can be called by all
		// three versions of operator* without any type conversions.
		Object &retrieve() const
		{
			return current->data;
		}

		// Protected constructor for const_iterator.
		// Expects a pointer that represents the current position.
		const_iterator(Node *p)
			: current(p)
		{
		}

	public:
		friend class List<Object>;
		// Public constructor for const_iterator.
		const_iterator()
			: current(NULL)
		{
		}

		// Return the object stored at the current position.
		// For const_iterator, this is an accessor with a
		// const reference return type.
		const Object &operator*() const
		{
			return this->retrieve();
		}

		const_iterator &operator++()
		{
			current = current->next;
			return *this;
		}

		const_iterator operator++(int)
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}

		const_iterator &operator--()
		{
			current = current->prev;
			return *this;
		}

		const_iterator operator--(int)
		{
			const_iterator old = *this;
			--(*this);
			return old;
		}

		bool operator==(const const_iterator &rhs) const
		{
			return current == rhs.current;
		}

		bool operator!=(const const_iterator &rhs) const
		{
			return !(*this == rhs);
		}
	};

	class iterator : public const_iterator
	{
	protected:
		// Protected constructor for iterator.
		// Expects the current position.
		iterator(Node *p)
			: const_iterator(p)
		{
		}

	public:
		friend class List<Object>;

		// Public constructor for iterator.
		// Calls the base-class constructor.
		// Must be provided because the private constructor
		// is written; otherwise zero-parameter constructor
		// would be disabled.
		iterator()
		{
		}

		Object &operator*()
		{
			return this->retrieve();
		}

		// Return the object stored at the current position.
		// For iterator, there is an accessor with a
		// const reference return type and a mutator with
		// a reference return type. The accessor is shown first.
		const Object &operator*() const
		{
			return const_iterator::operator*();
		}

		iterator &operator++()
		{
			this->current = this->current->next;
			return *this;
		}

		iterator operator++(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}

		iterator &operator--()
		{
			this->current = this->current->prev;
			return *this;
		}

		iterator operator--(int)
		{
			iterator old = *this;
			--(*this);
			return old;
		}
	};

	List()
	{
		init();
	}

	~List()
	{
		clear();
		delete head;
		delete tail;
	}

	List(const List &rhs)
	{
		init();
		*this = rhs;
	}

	const List &operator=(const List &rhs)
	{
		if (this == &rhs)
			return *this;
		clear();
		for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
			push_back(*itr);
		return *this;
	}

	// Return iterator representing beginning of list.
	// Mutator version is first, then accessor version.
	iterator begin()
	{
		return iterator(head->next);
	}

	const_iterator begin() const
	{
		return const_iterator(head->next);
	}

	// Return iterator representing endmarker of list.
	// Mutator version is first, then accessor version.
	iterator end()
	{
		return iterator(tail);
	}

	const_iterator end() const
	{
		return const_iterator(tail);
	}

	// Return number of elements currently in the list.
	int size() const
	{
		return theSize;
	}

	// Return true if the list is empty, false otherwise.
	bool empty() const
	{
		return size() == 0;
	}

	void clear()
	{
		while (!empty())
			pop_front();
	}

	// front, back, push_front, push_back, pop_front, and pop_back
	// are the basic double-ended queue operations.
	Object &front()
	{
		return *begin();
	}

	const Object &front() const
	{
		return *begin();
	}

	Object &back()
	{
		return *--end();
	}

	const Object &back() const
	{
		return *--end();
	}

	// void push_front(const Object &x)
	// {
	// 	insert(begin(), x);
	// }

	// void push_back(const Object &x)
	// {
	// insert(end(), x);
	// }

	//appends the value to its soreted position in the list
	void append(const Object &x)
	{
		if (empty())
			insert(iterator(head->next), x);
		else
		{
			iterator i;
			for (i = head->next; x > i.current->data; i++)
			{
			}
			insert(i, x);
		}
	}

	void
	pop_front()
	{
		erase(begin());
	}

	void pop_back()
	{
		erase(--end());
	}

	// Insert x before itr.
	iterator insert(iterator itr, const Object &x)
	{
		Node *p = itr.current;
		theSize++;
		return iterator(p->prev = p->prev->next = new Node(x, p->prev, p));
	}

	// Erase item at itr.
	iterator erase(iterator itr)
	{
		Node *p = itr.current;
		iterator retVal(p->next);
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		theSize--;

		return retVal;
	}

	iterator erase(iterator start, iterator end)
	{
		for (iterator itr = start; itr != end;)
			itr = erase(itr);

		return end;
	}

	void show()
	{
		for (iterator i = begin(); i != end(); i++)
		{
			cout << i.current->data << endl;
		}
	}
};

int main()
{
	List<int> v;
	//cout << "Physical size (capacity) " << v.capacity() << endl;
	// cout << "Logical size (count of values stored) " << v.size() << endl;

	v.append(94);
	v.append(35);
	v.append(72);
	v.append(27);
	v.append(76);

	//cout << "Physical size (capacity) " << v.capacity() << endl;
	cout << "Logical size (count of values stored) " << v.size() << endl;

	v.show();

	return 0;
}
