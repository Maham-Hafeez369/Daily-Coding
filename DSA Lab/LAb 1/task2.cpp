#include <iostream>
#include <string>

using namespace std;

// function to compute and return the
// sum of 1st n values of array a
// means return a[0]+a[1]+a[2]+...+a[n-1]
int sumArrayRecursive(int n, int a[])
{
	// write recursive code
	// int ans = 0;
	if (n == 0)
		return 0;
	return sumArrayRecursive(n - 1, a) + a[n - 1];

	// your code here
	// you can completely overwrite the
	// body of this function
	// return ans;
}

// a test case of sumArrayRecursive function
// verify it, and add more test cases
int main()
{
	int array[7] = {2, 7, 4, 4, 6, 9, 1};
	cout << "the sum of values in array is ";
	cout << sumArrayRecursive(7, array);
	cout << endl;

	return 0;
}