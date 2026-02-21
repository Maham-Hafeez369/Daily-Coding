#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    cout << "============================" << endl;
    for (int i = 1; i <= 3; i++)
    {
        srand(time(0) + i);
        int a = rand() % 150 + 1;
        cout << a << "\t";
        for (int j = 1; j <= 5; j++)
        {
            cout << a * j << " ";
        }
        cout << endl;
    }
    cout << "============================" << endl;

    return 0;
}