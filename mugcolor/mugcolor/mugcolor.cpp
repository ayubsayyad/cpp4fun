//Problem        : Mug Color
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include <set>

using namespace std;
 
int main(int argv, char* argc[])
{
    using namespace std;
 
	std::set<string> allMugs;
	allMugs.insert("White");
	allMugs.insert("Black");
	allMugs.insert("Blue");
	allMugs.insert("Red");
	allMugs.insert("Yellow");

    int numPeople;
    string mugcolor;
 
    cin >> numPeople;
    getline(cin, mugcolor);
 
    for (int ii = 0; ii < numPeople; ii++)
    {
        getline(cin, mugcolor);
		allMugs.erase(mugcolor);
		if(allMugs.size() == 1)
			break;
    }
	std::cout << *allMugs.begin() <<std::endl;

    return 0;

}