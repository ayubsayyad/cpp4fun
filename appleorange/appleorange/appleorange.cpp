//Problem        : Finals Spring 2015 - Apples and Oranges
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Pruint64_t out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 

#ifdef WIN32
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif

using namespace std;
int main()
{
    uint64_t a0,o0, d0, ap,op,d1;
    cin >> a0 >>o0>>d0>>ap>>op>>d1;

    uint64_t x = 0,y =0;
    uint64_t idx =0;
    
	uint64_t maxx = -1; uint64_t maxy = -1;
	//ap*x +op*y = 
	uint64_t val = (a0*ap + o0*op + -d1+d0);
    uint64_t maxval = (a0*ap + o0*op + -d1+d0)/ap;
	bool breakLoop = false;

	if(val <= 0)
	{
		cout << "Impossible" << endl;
		return 0;
	}

	for(uint64_t ii = maxval; ii >= 0; --ii)
	{
		if(breakLoop)
			break;
		for(uint64_t jj = 0; (val - op*jj) >= 0; ++jj)
		{
			if(0 == ((val - op*jj)%ap))
			{
				maxx = ii;
				breakLoop = true;
				break;
			}
		}
	}
	if(maxx == -1)
	{
		cout << "Impossible" << endl;
		return 0;
	}

	breakLoop = false;
	maxval = (a0*ap + o0*op + -d1+d0)/op;
	for(uint64_t ii = maxval; ii >= 0; --ii)
	{
		if(breakLoop)
			break;
		for(uint64_t jj = 0; (val - ap*jj) >= 0; ++jj)
		{
			if(0 == ((val - ap*jj)%op))
			{
				maxy = ii;
				breakLoop = true;
				break;
			}
		}
	}

	if(maxy == -1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	cout << maxx <<" " << maxy << endl;
}
