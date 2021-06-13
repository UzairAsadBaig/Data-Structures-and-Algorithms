#include <iostream>
#include <string>

using namespace std;

class LinkStack
{
protected:
    long sz;

    class listNode
    {
    public:
        int data;
        listNode *next;
        listNode(int d)
        {
            data = d;
            next = NULL;
        }
    };

    listNode *top;

public:
    LinkStack()
    {
        this->top = NULL;
        this->sz = 0;
    }

    ~LinkStack()
    {
        listNode *tmp = top;

        while (tmp != NULL)
        {
            listNode *tmp2 = tmp;
            tmp = tmp->next;
            delete tmp2;
        }
    }

    void push(const int &e)
    {
        if (top == NULL)
        {
            top = new listNode(e);
            this->sz++;
            return;
        }
        listNode *tmp = new listNode(e);
        tmp->next = top;
        top = tmp;
        this->sz++;
    }

    int pop()
    {
        if (this->isEmpty())
        {
            throw string("\nStack is empty,Value cannot be poped\n");
        }
        listNode *tmp = top;
        int ret = top->data;
        top = tmp->next;
        this->sz--;
        delete tmp;
        return ret;
    }

    int peek() const
    {
        return top->data;
    }

    bool isEmpty() const
    {
        return (this->top == NULL);
    }

    long size() const
    {
        return this->sz;
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