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
};

void makelist(Node *&head)
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
    cout << "Enter 10 number of the list: ";
    float num;
    cin >> num;
    Node *temp = head;
    if (head == nullptr)
    {
        head = new Node(num);
        temp = head;
    }
    for (int i = 1; i < 10; i++)
    {
        cin >> num;
        temp->next = new Node(num);
        temp = temp->next;
    }
    cout << "the following list is created" << endl;
    showlist(head);

    return;
}
void showlist(Node *head)
{
    for (Node *tmp = head; tmp != nullptr; tmp = tmp->next)
    {
        cout << tmp->info << ", ";
    }
    cout << '\b' << '\b' << '.' << endl;
}
void append(float data, Node *&head)
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
void insertAt(int index, float data, Node *&head)
{
    if (index == 0)
    {
        head = new Node(data, head);
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < index - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp != nullptr)
        {
            temp->next = new Node(data, temp->next);
        }
        else
        {
            cout << "Index out of bounds" << endl;
        }
    }
}

int main()
{
    Node *list = nullptr;
    makelist(list);

    // your code to solve task should be here

    // your code ends here

    cout << "the update list is" << endl;
    for (Node *tmp = list; tmp != nullptr; tmp = tmp->next)
    {
        cout << tmp->info << ", ";
    }
    cout << '\b' << '\b' << '.' << endl;

    return 0;
}