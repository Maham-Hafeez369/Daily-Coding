#include <iostream>
using namespace std;
class Node
{
    double data;

public:
    Node *next;
    Node(double data)
    {
        this->data = data;
        this->next = NULL;
    }
    double getData()
    {
        return data;
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
    void append(double data)
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
    // void remove(double data)
    // {
    //     if (head == NULL)
    //     {
    //         cout << "List is empty" << endl;
    //         return;
    //     }
    //     if (head->getData() == data)
    //     {
    //         Node *temp = head;
    //         head = head->next;
    //         delete temp;
    //         return;
    //     }
    //     Node *temp = head;
    //     while (temp->next != NULL)
    //     {
    //         if (temp->next->getData() == data)
    //         {
    //             Node *toDelete = temp->next;
    //             temp->next = temp->next->next;
    //             delete toDelete;
    //             return;
    //         }
    //         temp = temp->next;
    //     }
    //     cout << "Value not found in the list" << endl;
    // }
};
int main()
{

    return 0;
}