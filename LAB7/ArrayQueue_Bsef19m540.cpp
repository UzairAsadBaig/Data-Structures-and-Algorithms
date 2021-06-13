#include <iostream>
#include <string>

using namespace std;

class ArrayQueue
{
protected:
    int *data;
    long arraySize;
    long top;

    void create(int sz)
    {
        this->data = new int[sz];
        this->arraySize = sz;
        this->top = 0;
    }

    void increaseSize()
    {
        // will be implemented later
    }

public:
    ArrayQueue()
    {
        this->create(10); // 10 is default size and can be changed
    }

    ArrayQueue(int sz)
    {
        this->create(sz);
    }

    ~ArrayQueue()
    {
        delete[] this->data;
        this->data = NULL;
    }

    void push(const int &e)
    {
        if (this->isFull())
        {
            this->increaseSize();
        }
        if (this->isFull())
        {
            throw string("ArrayQueue is full!!");
        }

        this->data[this->top] = e;
        this->top++;
    }

    int pop()
    {
        int ro = data[0];
        for (int i = 0; i < top - 1; i++)
        {
            data[i] = data[i + 1];
        }
        top--;
        return ro;
    }

    int peek() const
    {
        if (this->isEmpty())
        {
            throw string("ArrayQueue is empty!!");
        }

        return data[0];
    }

    bool isEmpty() const
    {
        return (this->top == 0);
    }

    bool isFull() const
    {
        return (this->top == this->arraySize);
    }

    long size() const
    {
        return this->top;
    }
};

int main()
{
    ArrayQueue *s = new ArrayQueue;

    s->push(12);
    s->push(33);
    s->push(28);
    s->push(89);
    s->push(44);
    cout << s->pop() << endl;
    s->push(57);
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->peek() << endl;
    s->push(94);
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->peek() << endl;
    //cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << (s->isEmpty() ? "Empty Stack" : "Non empty stack") << endl;
    try
    {
        cout << s->pop() << endl;
    }
    catch (string s)
    {
        cout << "Exception caught: " << s << endl;
    }

    delete s;

    return 0;
}