#include <iostream>
#include <string>

using namespace std;

class LinkQueue
{
protected:
    long sizeOfList;

    class node
    {
    public:
        int data;
        node *next;
        node *back;
        node(int d)
        {
            data = d;
            next = NULL;
            back = NULL;
        }
    };
    node *front;
    node *rear;

public:
    LinkQueue()
    {
        this->front = NULL;
        this->rear = NULL;
        this->sizeOfList = 0;
    }

    ~LinkQueue()
    {
        node *tmp = front;

        while (tmp != NULL)
        {
            node *junk = tmp;
            tmp = tmp->next;
            delete junk;
        }
    }

    void enqueue(const int &e)
    {
        if (front == NULL)
        {
            front = new node(e);
            rear = front;
            this->sizeOfList++;
            return;
        }
        node *tmp = new node(e);
        tmp->next = front;
        tmp->back = NULL;
        tmp->next->back = tmp;
        front = tmp;
        this->sizeOfList++;
    }

    int dequeue()
    {
        if (this->isEmpty())
        {
            throw string("\nStack is empty,Value cannot be dequeueed\n");
        }
        node *tmp = rear;
        rear = rear->back;
        sizeOfList--;
        return tmp->data;
    }

    int peek() const
    {
        return rear->data;
    }

    bool isEmpty() const
    {
        return (this->front == NULL);
    }

    //As ListStack is based on dynamic allocation that does not have any limit,hence there no use of creating isFull function.

    // bool isFull() const
    // {
    //     return (this->front == this->sizeOfList);
    // }

    long size() const
    {
        return this->sizeOfList;
    }
};

int main()
{
    LinkQueue *s = new LinkQueue;

    s->enqueue(12);
    s->enqueue(33);
    s->enqueue(28);
    s->enqueue(89);
    s->enqueue(44);
    cout << s->dequeue() << endl;
    s->enqueue(57);
    cout << s->dequeue() << endl;
    cout << s->dequeue() << endl;
    cout << s->peek() << endl;
    s->enqueue(94);
    cout << s->dequeue() << endl;
    cout << s->dequeue() << endl;
    cout << s->peek() << endl;
    //cout << s->dequeue() << endl;
    cout << s->dequeue() << endl;
    cout << (s->isEmpty() ? "Empty Stack" : "Non empty stack") << endl;
    try
    {
        cout << s->dequeue() << endl;
    }
    catch (string s)
    {
        cout << "Exception caught: " << s << endl;
    }
    delete s;

    return 0;
}