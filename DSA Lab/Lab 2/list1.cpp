#include <iostream>
#include <string>
#include <limits>
#include <cmath>
using namespace std;
/*
I have not taken any direct help to solve this task.
Roll No:BITF24M512
Name: Maham Hafeez
*/

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
    Node *getHead()
    {
        return head;
    }
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
    double at(int index)
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            if (count == index - 1)
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
    void push_front(float data)
    {
        Node *newNode = new Node(data, head);
        head = newNode;
    }
    void push_back(float data)
    {
        append(data);
    }
    int length()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void remove_front()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
};
void makelist(linkedList &list)
{
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
    cout << "the following list is created" << endl;
    list.show();
}
int main()
{
    linkedList mylist;
    makelist(mylist);

    // your code should make the list class like vector class of STL, as much as possible for you, e.g., should work at least demonstrate the following

    // mylist.push_back(23.6); // add value at end
    mylist.push_back(23.6);
    // mylist.push_back(43.1);
    mylist.push_back(43.1);
    // mylist.push_back(84.5);
    mylist.push_back(84.5);
    // mylist.push_back(66.3);
    mylist.push_back(66.3);
    // mylist.push_front(66.3); // add value at beginning
    mylist.push_front(66.3);
    // mylist.show(); // display whole list
    mylist.show();
    // mylist.remove(84.5); // remove value if stored in list
    mylist.remove(84.5);
    // cout << mylist.length(); // return count of values stored in the list
    cout << "Length of the list is: " << mylist.length() << endl;
    // mylist.remove_front(); // remove first/front value of list
    mylist.remove_front();
    // cout << mylist.at(2); // return zero based ith value of list
    cout << "Value at index 2 is: " << mylist.at(2) << endl;

    // what is NOT GOOD in the following code
    // Because a show function is already defined
    // in the linkedList class, we should use that
    // function to display the list instead of directly
    // accessing the head pointer and traversing the list.
    // This violates the principle of encapsulation and makes
    // the code less maintainable. If we want to change the internal
    // implementation of the linked list, we would also need to change
    // this code, which is not ideal. Instead, we should simply call
    // mylist.show() to display the list, which will ensure that any
    // changes to the internal implementation of the linked list
    // do not affect this part of the code.
    cout << "the update list is" << endl;
    for (Node *tmp = mylist.getHead(); tmp != nullptr; tmp = tmp->next)
    {
        cout << tmp->info << ", ";
    }
    cout << '\b' << '\b' << '.' << endl;

    return 0;
}