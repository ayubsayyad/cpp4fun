//Problem        : Expecto Palindronum
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
using namespace std;

bool isPalendrom(const string& s, int length)
{
	int begin =0;
	int end = length-1;
	while(begin < end) 
	{
		if(s.c_str()[begin] != s.c_str()[end])
			return false;
		begin++;end--;
	}
	return true;
}
int main() {

	string input;
	getline(cin, input);
	int idx = input.size();

	for(;idx != 1; --idx)
	{
		if(isPalendrom(input, idx))
			break;
	}
	std::cout << input.size() + (input.size() - idx) << std::endl;

    return 0;
}
