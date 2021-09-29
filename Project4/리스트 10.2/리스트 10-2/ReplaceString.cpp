#include <iostream>
#include <string>
using namespace std;

bool replaceString(string& s, const string& oldSubStr, const string& newSubStr);

int main()
{
	cout << "<¸®½ºÆ® 10.2>" << endl;
	cout << "Enter a string s, oldSubStr, and newSubStr: ";
	string s, oldSubStr, newSubStr;
	cin >> s >> oldSubStr >> newSubStr;

	bool isReplaced = replaceString(s, oldSubStr, newSubStr);

	if (isReplaced)
		cout << "The replaced string is " << s << endl;
	else
		cout << "No matches" << endl;

	return 0;
}

bool replaceString(string& s, const string& oldSubStr, const string& newSubStr)
{
	bool isReplaced = false;
	int currentPosition = 0;
	while (currentPosition < s.length())
	{
		int position = s.find(oldSubStr, currentPosition);
		if (position == string::npos)
			return isReplaced;
		else
		{
			s.replace(position, oldSubStr.length(), newSubStr);
			currentPosition = position + newSubStr.length();
			isReplaced = true;
		}
	}

	return isReplaced;
}