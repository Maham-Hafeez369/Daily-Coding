#include <iostream>
#include <string>
#include <limits>
#include <cmath>

/*
I have not taken any direct help to solve this task.
Roll No:BITF24M512
Name: Maham Hafeez
*/

using namespace std;

class Node
{
public:
    float info;
    Node *next;
    Node()
    {
        info = numeric_limits<float>::infinity();
        next = nullptr;
    }
    Node(float x)
    {
        info = x;
        next = nullptr;
    }
    Node(float x, Node *n)
    {
        info = x;
        next = n;
    }
    float getData()
    {
        return info;
    }
};

class linkedList
{
    Node *head;

public:
    linkedList()
    {
        head = NULL;
    }
    void append(float data)
    {
        if (head == NULL)
        {
            head = new Node(data);
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new Node(data);
        }
    }
    void show()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->getData() << " ";
            temp = temp->next;
        }
        cout << '\b' << '\b' << '.' << endl;
    }
    double ValueAt(int index)
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            if (count == index)
            {
                return temp->getData();
            }
            count++;
            temp = temp->next;
        }
        cout << "Index out of bounds" << endl;
        return -1; // Return -1 if index is out of bounds
    }
    void insertAt(int index, float data)
    {
        if (index < 0)
        {
            cout << "Index cannot be negative" << endl;
            return;
        }
        if (index == 0)
        {
            Node *newNode = new Node(data, head);
            head = newNode;
            return;
        }
        Node *temp = head;
        int count = 0;
        while (temp != NULL && count < index - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)
        {
            cout << "Index out of bounds" << endl;
            return;
        }
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void remove(float data)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *t1 = head;
        Node *t2 = head->next;
        while (head->getData() == data && head != nullptr) // if the head node itself contains the data to be removed, we need to update the head pointer and delete the old head node. We repeat this process until we find a head node that does not contain the data or we reach the end of the list.
        {
            delete t1;
            head = t2;
            t1 = head;
            t2 = head->next;
        }
        while (t2 != nullptr) // we need to check if the current node (t2) contains the data to be removed. If it does, we update the next pointer of the previous node (t1) to skip the current node and then delete the current node. If it does not contain the data, we simply move both pointers forward to continue traversing the list.
        {
            if (t2->getData() == data)
            {
                t1->next = t2->next;
                delete t2;
                t2 = t1->next;
            }
            else
            {
                t1 = t2;
                t2 = t2->next;
            }
        }
    }
    void removeNextOf(float data)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *t1 = head;
        Node *t2 = head->next;
        while (t2 != nullptr)
        {
            if (t1->getData() == data)
            {
                t1->next = t2->next;
                delete t2;
                t1 = t1->next;
                if (t1 != nullptr)
                {
                    t2 = t1->next;
                }
            }
            else
            {
                t1 = t2;
                t2 = t2->next;
            }
        }
    }
    void removePreviousOf(float data)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *t1 = head;
        Node *t2 = head->next;
        while (t2->next != nullptr)
        {
            if (t2->next->getData() == data)
            {
                t1->next = t2->next;
                delete t2;
                t1 = t1->next;
                if (t1 != nullptr)
                {
                    t2 = t1->next;
                }
            }
            else
            {
                t1 = t2;
                t2 = t2->next;
            }
        }
    }
    void removeith(int i)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (i < 0)
        {
            cout << "Index cannot be negative" << endl;
            return;
        }
        if (i == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *t1 = head;
        Node *t2 = head->next;
        for (int count = 1; t2 != nullptr && count < i - 1; count++)
        {
            t1 = t2;
            t2 = t2->next;
        }
        if (t2 == nullptr)
        {
            cout << "Index out of bounds" << endl;
            return;
        }
        else
        {
            t1->next = t2->next;
            delete t2;
            cout << "Element at index " << i << " removed" << endl;
        }
    }
};
void makelist(linkedList &list)
{
    // not a good approach, but it makes a linked list
    // head = new Node(30);
    // head->next = new Node(90);
    // head->next->next = new Node(50);
    // head->next->next->next = new Node(10);
    // head->next->next->next->next = new Node(70);
    // head->next->next->next->next->next = new Node(20);
    // head->next->next->next->next->next->next = new Node(40);
    // head->next->next->next->next->next->next->next = new Node(80);
    // head->next->next->next->next->next->next->next->next = new Node(60);
    cout << "Enter the number of elements to creat a new list the list: ";
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) // after creating a class the whole function is easy to create
    {
        float data;
        cout << "Enter element " << i + 1 << ": ";
        cin >> data;
        list.append(data);
    }
    // Node *temp = head;
    // if (head == nullptr)
    // {
    //     head = new Node(num);
    //     temp = head;
    // }
    // for (int i = 1; i < 10; i++)
    // {
    //     cin >> num;
    //     temp->next = new Node(num);
    //     temp = temp->next;
    // }
    cout << "the following list is created" << endl;
    list.show();
}
int main()
{
    linkedList list;
    makelist(list);

    // your code to solve task should be here
    list.removePreviousOf(10);
    // your code ends here

    cout << "the update list is" << endl;
    list.show();

    return 0;
}