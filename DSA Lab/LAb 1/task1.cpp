#include <iostream>
#include <string>

using namespace std;

// function to compute and return the 
// sum of 1st n values of array a
// means return a[0]+a[1]+a[2]+...+a[n-1]
int sumArrayIterative(int n, int a[])
{
	int ans = 0;
	
	int j=0;
	while(j < n)
	{
		ans += a[j];
		j += 1;
	}
	return ans;
}


// a test case of sumArrayIterative function
// verify it, and add more test cases
int main()
{
	int array[7] = {2, -7, 4, -4, 6, 9, 1};
	cout << "the sum of values in array is ";
	cout << sumArrayIterative(7, array);
	cout << endl;

	return 0;
}