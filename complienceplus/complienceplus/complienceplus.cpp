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

bool canMakePalendrom(const std::string& str)
{
	std::string input(str);
	std::sort(input.begin(), input.end());
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

int factorial(int num)
{
	int factorial = 1;
	for(int idx = 1; idx <= num; ++idx)
    {
		factorial=factorial*idx;
    }

	return factorial;
}
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

	std::string input;
	std::getline(std::cin, input);

	if(!canMakePalendrom(input))
	{
		std::cout << 0 <<std::endl;
		return 0;
	}

	std::sort(input.begin(), input.end());
	char curr = input.c_str()[0];
	int currcount = 0;
	int accDiv = 1;
	for(int idx = 1; idx < input.size(); ++idx)
	{
		if(curr == input.c_str()[idx])
		{
			++currcount;
		}
		else
		{
			++currcount;
			if(currcount > 3)
			{
				accDiv *= factorial(currcount/2);
			}
			curr = input.c_str()[idx];
			currcount = 0;
		}
	}
	++currcount;
	if(currcount > 3)
		accDiv *= factorial(currcount/2);

	std::cout << factorial(input.size()/2)/accDiv << std::endl;

    return 0;
}
