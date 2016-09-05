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

uint64_t lcm(uint64_t a, uint64_t b, uint64_t c) 
{ 
    uint64_t i; 
    for(i=1;i<=a*b*c;i++) 
    { 
        if(i%a == 0 && i%b == 0 && i%c == 0) 
        { 
            return i;
        } 
    }

    return 0;
} 

int main()
{
    uint64_t a0,o0, d0, ap,op,d1;
    cin >> a0 >>o0>>d0>>ap>>op>>d1;

    uint64_t x = 0,y =0;
    uint64_t idx =0;
    
    x = (a0*ap + o0*op + idx*op-d1+d0)/ap;
    uint64_t mod = (a0*ap + o0*op + idx*op-d1+d0)%ap;
    if(mod)
    {
        if(ap > op)
        {
            y = mod/op;
            mod = mod % op;
        }
        if(mod)
        { 
			uint64_t idx;
			for(idx = 1; idx < x; ++idx)
			{
				if((mod + ap*idx)% op == 0)
					break;
			}
			y += (mod + ap*idx)/op;
            x -= idx;
        }
    }
    uint64_t tmpx = x;
    if ((x*ap+y*op) != (a0*ap + o0*op + d0 -d1))
    {
        cout <<"Impossible" << endl;
        return 0;
    }

	x = 0;
    y = (a0*ap + o0*op + idx*ap-d1+d0)/op;
    mod = (a0*ap + o0*op + idx*ap-d1+d0)%op;
    if(mod)
    {
        if(op > ap)
        {
			x = mod/ap;
            mod = mod % ap;
        }
        if(mod)
        { 
			uint64_t idx;
			for(idx = 1; idx < y; ++idx)
			{
				if((mod + op*idx)% ap == 0)
					break;
			}
			x += (mod + op*idx)/op;
            y -= idx;
        }
    }
    
    if ((x*ap+y*op) != (a0*ap + o0*op + d0 -d1))
    {
        cout <<"Impossible" << endl;
        return 0;
    }
    
    
    cout << tmpx << " " << y <<std::endl;

    return 0;
}

