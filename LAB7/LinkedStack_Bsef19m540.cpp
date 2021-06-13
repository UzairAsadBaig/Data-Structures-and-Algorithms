#include <iostream>
#include <string>

using namespace std;

class LinkStack
{
protected:
    long sizeOfList;

    class node
    {
    public:
        int data;
        node *next;
        node(int d)
        {
            data = d;
            next = NULL;
        }
    };
    node *top;

public:
    LinkStack()
    {
        this->top = NULL;
        this->sizeOfList = 0;
    }

    ~LinkStack()
    {
        node *tmp = top;

        while (tmp != NULL)
        {
            node *junk = tmp;
            tmp = tmp->next;
            delete junk;
        }
    }

    void push(const int &e)
    {
        if (top == NULL)
        {
            top = new node(e);
            this->sizeOfList++;
            return;
        }
        node *tmp = new node(e);
        tmp->next = top;
        top = tmp;
        this->sizeOfList++;
    }

    int pop()
    {
        if (this->isEmpty())
        {
            throw string("\nStack is empty,Value cannot be poped\n");
        }
        node *tmp = top;
        top = tmp->next;
        int a = tmp->data;
        delete tmp;
        this->sizeOfList--;
        return a;
    }

    int peek() const
    {
        return top->data;
    }

    bool isEmpty() const
    {
        return (this->top == NULL);
    }

    //As ListStack is based on dynamic allocation that does not have any limit,hence there no use of creating isFull function.

    // bool isFull() const
    // {
    //     return (this->top == this->sizeOfList);
    // }

    long size() const
    {
        return this->sizeOfList;
    }
};

int main()
{
    LinkStack *s = new LinkStack;

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