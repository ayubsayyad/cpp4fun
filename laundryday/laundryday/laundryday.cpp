//Problem        : Laundry Day
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
struct str_comp
{
    struct case_insensitive_compare : public std::binary_function<unsigned char,unsigned char,bool> 
    {
      bool operator() (const unsigned char& c1, const unsigned char& c2) const 
	  {
          return tolower (c1) < tolower (c2); 
      }
    };
    bool operator() (const std::string & s1, const std::string & s2) const 
	{
      return std::lexicographical_compare(
        s1.begin (), s1.end (), s2.begin (), s2.end (),
			case_insensitive_compare ());
    }
};

int main() 
{
	std::map<string, int, str_comp> laundry;
	
	std::map<string, int, str_comp>::iterator iter;
    while(true)
    {
		string cloth;
		getline(cin, cloth);
		if(cloth == "")
			break;
		iter = laundry.find(cloth);
		if(iter == laundry.end())
			laundry[cloth] = 1;
		else
			iter->second++;
    }

	for(iter = laundry.begin(); iter != laundry.end(); ++iter)
	{
		int count = iter->second;
		size_t fiind = iter->first.rfind(" sock");
		//if(fiind != string::npos)
		if(5 == (iter->first.size() - fiind))
		{
			std::cout << count/2 <<"|" << iter->first << std::endl;
			if((0 != (count % 2)) &&  (0 != count/2))
				std::cout << 0 <<"|" << iter->first << std::endl;
		}
		else
		{
			std::cout << count <<"|" << iter->first << std::endl;
		}
	}
    return 0;
}
