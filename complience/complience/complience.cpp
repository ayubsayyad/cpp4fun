//Problem        : A Compliance Problem
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 

bool canMakePalendrom(const std::string& input)
{
	int exceptions = input.size()%2;
	for(int i = 0; (i + 1) < input.size(); i += 2)
	{
		if(input.c_str()[i] != input.c_str()[i+1])
		{
			--exceptions;
			--i;
		}

		if(exceptions < 0)
		{
			return false;
		}
	}

	return true;
}

int main() {

	std::string input;
	std::getline(std::cin, input);
	std::sort(input.begin(), input.end());
	std::cout << (canMakePalendrom(input)? "yes" : "no") <<std::endl;

    return 0;
}
