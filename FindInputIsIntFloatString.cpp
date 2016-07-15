#include <iostream>

using namespace std;

int main()
{
	int i;
	int numfound = 0;
	int dotsfound = 0;
	int negfound = 0;
	string str;

	cin >> str;

	for (i = 0;(i < str.length()) && (str[i]); i++)
	{
		numfound += ((str[i] >= '0') && (str[i] <= '9'));
		dotsfound += (str[i] == '.');
		negfound += (str[i] == '-');
	}
	if (numfound == str.length() || ((negfound == 1) && (numfound == str.length() - 1)))
		cout << "This input is of type Integer." << endl;
	else if ((dotsfound == 1) && (numfound == str.length() - 1))
		cout << "This input is of type Float." << endl;
	else
		cout << "This input is of type string." << endl;
}

