//Problem        : Finals Spring 2015 - Matching Gloves
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include <map>

using namespace std;
bool isPalendrome(const std::string& str)
{
	int start = 0;
	int end = str.size() -1;
	while(start < end)
	{
		if(str.c_str()[start] != str.c_str()[end])
			return false;
		++start; --end;
	}
	return true;
}


int main() {

	int numEntries;
    string item;
	std::map<string, std::pair<int, int> > winterItems;
	typedef std::map<string, std::pair<int, int> >::value_type VALUE;
	std::map<string, std::pair<int, int> >::iterator iter;
    cin >> numEntries;
    getline(cin, item);
 
    for (int ii = 0; ii < numEntries; ii++)
    {
        getline(cin, item);
		if(isPalendrome(item))
			continue;

		iter = winterItems.find(item);
		if(iter != winterItems.end())
		{
			iter->second.first++;
		}
		else
		{
			string ritem(item);
			std::reverse(ritem.begin(), ritem.end());
			iter = winterItems.find(ritem);
			if(iter != winterItems.end())
			{
				iter->second.second++;
			}
			else
			{
				winterItems.insert(VALUE(item, std::pair<int, int>(1, 0)));
			}
		}
    }

	int numPairs = 0;
	for(iter = winterItems.begin(); iter != winterItems.end(); ++iter)
	{
		if(iter->second.first != iter->second.second)
		{
			numPairs = -1;
			break;
		}
		numPairs += iter->second.first;
	}
	std::cout << numPairs << std::endl;
    return 0;
}
