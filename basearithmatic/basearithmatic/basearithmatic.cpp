// basearithmatic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Problem        : Base Arithmetic
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include <cmath>

const char MinAlpha = 'A';
const char MaxAlpha = 'F';


const char MinDigit = '0';
const char MaxDigit = '9';

unsigned short  getBase(const std::string& num)
{
	unsigned short basefornum = 2;
	for(int idx = 0; idx < num.size(); ++idx)
	{
		if(num.c_str()[idx] > MaxDigit)
		{
			if(basefornum < (11 + num.c_str()[idx] - MinAlpha))
			{
				basefornum = (11 + num.c_str()[idx] - MinAlpha);
			}
		}
		else
		{
			if(basefornum < (1+num.c_str()[idx] - MinDigit))
			{
				basefornum = (1+num.c_str()[idx] - MinDigit);
			}
		}
	}
	return basefornum;
}

long long convertToDecimal(int base, const std::string& num)
{
	long long numindecimal = 0;
	int power = 0;
	for(int idx = num.size()-1; idx >= 0; --idx, ++power)
	{
		int number = 0;
		if(num.c_str()[idx] > MaxDigit)
		{
			//alphabet
			number = 10 + num.c_str()[idx] - MinAlpha;
		}
		else
		{
			//numer
			number = num.c_str()[idx] - MinDigit;
		}
		numindecimal += number * std::pow(base, power);
	}

	return numindecimal;
}
int main() {

	using namespace std;
	string num1;
	string num2;
    getline(cin, num1);
	getline(cin, num2);

	unsigned short basefornum1 = getBase(num1);
	unsigned short basefornum2 = getBase(num2);
	if(basefornum1 > 16 || basefornum2 > 16)
	{
		std::cout << "input error" <<std::endl;
		return -1;
	}

	std::cout << convertToDecimal(basefornum1, num1)+convertToDecimal(basefornum2, num2);
    return 0;
}
