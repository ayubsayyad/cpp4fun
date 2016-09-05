//Problem        : Matching Datasets
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include <vector>
#include <sstream>


using namespace std;

int main() {

	int numEntries =0;
	cin >> numEntries;
	string setEntry;
	getline(cin, setEntry); //clear input

	std::vector<vector<double> > originalSet;
    for(int ii =0; ii < numEntries; ++ii)
    {
		vector<double> row;
		getline(cin, setEntry);
		istringstream f(setEntry);
		string s;    
		while (getline(f, s, ',')) {
			row.push_back(atof(s.c_str()));
		}
		std::sort(row.begin(), row.end());
		originalSet.push_back(row);
    }
	std::vector<vector<double> > newSet;
    for(int ii =0; ii < numEntries; ++ii)
    {
		vector<double> row;
		getline(cin, setEntry);
		istringstream f(setEntry);
		string s;    
		while (getline(f, s, ',')) {
			row.push_back(atof(s.c_str()));
		}
		std::sort(row.begin(), row.end());
		newSet.push_back(row);
    }

	std::vector<vector<double> >::iterator iter = originalSet.begin();
	for(; iter != originalSet.end(); ++iter)
	{
		int mindiff = INT_MAX;
		int mindiffIdx = 0;
		std::vector<vector<double> >::iterator newSetIter = newSet.begin();
		for(;newSetIter != newSet.end(); ++newSetIter)
		{
			int tmpmindiff = 0;
			for(unsigned int idx = 0; idx < (*newSetIter).size(); ++idx)
			{
				tmpmindiff += std::abs((int)((*newSetIter)[idx]-(*iter)[idx]));
			}

			if(tmpmindiff < mindiff)
			{
				mindiffIdx = newSetIter - newSet.begin();
				mindiff = tmpmindiff;
			}
		}
		std::cout << (iter - originalSet.begin()) << "," << mindiffIdx << std::endl;
	}

    return 0;
}
