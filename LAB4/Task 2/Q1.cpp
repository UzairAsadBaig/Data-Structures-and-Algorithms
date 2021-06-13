// what are the mistakes in the code

#include <iostream>

using namespace std;

class LinkedList
{
private:
    class ListNode
    {
    public:
        int data;
        ListNode *next;
        ListNode(int d)
        {
            data = d;
            next = NULL;
        }
    };

    ListNode *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    ~LinkedList()
    {
        // implement yourself
    }

    void append(int d)
    {
        if (head == NULL)
        {
            head = new ListNode(d);
            return;
        }

        ListNode *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new ListNode(d);
    }

    void erase(int d)
    {
        ListNode *tmp = head;
        //while(tmp != NULL && tmp->next != NULL && tmp->data != d)

                //There was a logical error,the tmp was moving till the node to be deleted.I replaced temp->data with tmp->next->data.Now the temp will point to the node that lies before the node to be deleted.
        while (tmp->next->data != d)
        {
            tmp = tmp->next;
        }
        if (tmp != NULL)
        {
            ListNode *junk = tmp->next;
            tmp->next = tmp->next->next;
            // OR tmp->next = junk->next;
            delete junk;
        }
    }

    void display()
    {
        ListNode *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
};

int main()
{
    LinkedList c;

    c.append(30);
    c.append(90);
    c.append(20);
    c.append(70);
    c.append(50);

    c.erase(20);

    c.display();
}
