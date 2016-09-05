//Problem        : Messed up Rugby
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 


int main() 
{
	int score;
	std::cin >> score;

	bool scoreExist = false;
	for(int ii=0; ii*7 <= score; ++ii)
	{
		int sum7 = ii*7;
		for(int jj=0; jj*3 + sum7 <= score; ++jj)
		{
			int sum3 = jj*3 + sum7;
			for(int kk=0; kk*2 + sum3 <= score; ++kk)
			{
				if(kk*2 + sum3 == score)
				{
					std::cout << ii <<" " << jj << " " << kk << std::endl;
					scoreExist = true;
				}
			}
		}
	}
	if(!scoreExist)
	{
		std::cout << 0 <<" " << 0 << " " << 0 << std::endl;
	}
    return 0;
}
