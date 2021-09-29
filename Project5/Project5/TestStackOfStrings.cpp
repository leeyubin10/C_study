#include "StackOfStrings.h"
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	StackOfStrings stack;

	/*for (int i = 0; i < 10; i++)
		stack.push(string("STR") + to_string(i));*/

	stringstream ss;
	for(int i=0; i<10; i++)
	{
		ss << "STR" << i;
		stack.push(ss.str());
		ss.str("");
	}
	

	while (!stack.isEmpty())
		cout << stack.pop() << " ";

	return 0;
}