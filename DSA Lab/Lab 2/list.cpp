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

class List
{
    public:
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

        Node *head;
        
        List()
        {
            head = nullptr;
        }

        void make()
        {
            // not a good approach, but it makes a linked list
            head = new Node(30);
            head->next = new Node(90);
            head->next->next = new Node(50);
            head->next->next->next = new Node(10);
            head->next->next->next->next = new Node(70);
            head->next->next->next->next->next = new Node(20);
            head->next->next->next->next->next->next = new Node(40);
            head->next->next->next->next->next->next->next = new Node(80);
            head->next->next->next->next->next->next->next->next = new Node(60);
            
            cout << "the following list is created" << endl;
            for(Node *tmp = head; tmp != nullptr; tmp = tmp->next)
            {
                cout << tmp->info << ", ";
            }
            cout << '\b' << '\b' << '.' << endl;
            
            return;
        }

};


int main()
{
	List mylist;
    mylist.make();
    
    // your code should make the list class like vector class of STL, as much as possible for you, e.g., should work at least demonstrate the following
    
    // mylist.push_back(23.6); // add value at end
    // mylist.push_back(43.1);
    // mylist.push_back(84.5);
    // mylist.push_back(66.3);
    // mylist.push_front(66.3); // add value at beginning
    // mylist.show(); // display whole list
    // mylist.remove(84.5); // remove value if stored in list
    // cout << mylist.length(); // return count of values stored in the list
    // mylist.remove_front(); // remove first/front value of list
    // cout << mylist.at(2); // return zero based ith value of list
    // cout << mylist.length();



    // what is NOT GOOD in the following code
    
    cout << "the update list is" << endl;
    for(List::Node *tmp = mylist.head; tmp != nullptr; tmp = tmp->next)
    {
        cout << tmp->info << ", ";
    }
    cout << '\b' << '\b' << '.' << endl;

	return 0;
}