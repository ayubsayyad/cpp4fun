#include <algorithm>
#include <iostream>
#include <vector>
 
int main()
{
    int data[] = { 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
    std::vector<int> v(data, data+10);
	std::sort(v.begin(), v.end()); 
	
	std::vector<int>::iterator itr = v.begin();
	while(itr < v.end())
	{
		int num_items1 = std::count(v.begin(), v.end(), *itr);
		std::cout << 
	}
 
}