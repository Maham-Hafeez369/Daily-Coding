#include <iostream>
#include <string>

using namespace std;

// function to return the length of
// c-string (a \0 terminated char array)
int cStrLen(const char s[])
{
	// write recursive code

	if (*s == '\0')
	{
		return 0;
	}

	// your code here
	// you can completely overwrite the
	// body of this function
	return 1 + cStrLen(++s);
}

// a test case of cStrLen function
// verify it, and add more test cases
int main()
{
	cout << "the length for c-string" << endl;
	cout << "Alpha" << " is " << cStrLen("Alpha") << endl;
	cout << "A quick brown fox jumps over the lazy dog" << " is " << cStrLen("A quick brown fox jumps over the lazy dog") << endl;
	cout << endl;

	return 0;
}
