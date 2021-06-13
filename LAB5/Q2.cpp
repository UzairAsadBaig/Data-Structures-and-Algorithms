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

    void insertBefore(int d, int e)
    {
        if (head == NULL)
        {
            return;
        }

        if (head->data == e)
        {
            ListNode *tmp = new ListNode(d);
            tmp->next = head;
            head = tmp;
            return;
        }

        ListNode *tmp = head;
        while (tmp != NULL && tmp->next->data != e)
        {
            tmp = tmp->next;
        }

        if (tmp != NULL)
        {
            ListNode *nn = new ListNode(d);
            nn->next = tmp->next;
            tmp->next = nn;
        }
    }

    void erase(int d)
    {
        ListNode *tmp = head;
        while (tmp != NULL && tmp->next != NULL && tmp->next->data != d)
        // while (tmp->next->data != d)
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

    //Prototype of a function to count a specific value in its nodes
    int countOf(int value)
    {
        int count = 0;
        if (head != NULL)
        {
            ListNode *temp = head;
            while (temp != NULL)
            {
                if (temp->data == value)
                {
                    count++;
                }
                temp = temp->next;
            }
        }

        return count;
    }
};

int main()
{
    LinkedList c;

    c.append(30);
    c.append(90);
    c.append(20);
    c.append(70);
    c.append(20);
    c.append(50);
    c.append(20);

    // c.insertBefore(333, 30);
    cout << "The count is " << c.countOf(20) << endl;
    //c.erase(20);

    c.display();
}
