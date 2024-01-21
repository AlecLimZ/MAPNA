#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <unordered_map>

using namespace std;

int main(void)
{
	ifstream	MyFlag("flags.txt");
	string		mytext;
	int			alphabet = 0;
	int			number = 0;
	int			symbol = 0;

	while (getline(MyFlag, mytext))
	{
		unordered_map<char, int>	count;
		cout << mytext << endl;
		for (int i = 0; i < mytext.length(); i++)
		{
			count[mytext[i]]++; // unordered_map store each letter, if got duplicate, it wont add but add 1 to its second value.
			// any idea to implement something to determine which is true or false,
			alphabet = isalpha(mytext[i]) ? alphabet + 1 : alphabet;
			number = isdigit(mytext[i]) ? number + 1 : number;
			symbol = !isalpha(mytext[i]) && !isdigit(mytext[i]) ? symbol + 1 : symbol;
		}
		for (auto it : count)
		{
			if (it.second > 1)
				cout << it.first << ", count = " << it.second << endl;
		}
		cout << "Text length: " << mytext.length() << endl;
		cout << "Letters: " << alphabet << endl;
		cout << "Numbers: " << number << endl;
		cout << "Symbol: " << symbol << endl;
		alphabet = 0;
		number = 0;
		symbol = 0;
	}
	MyFlag.close();
	return (0);
}
