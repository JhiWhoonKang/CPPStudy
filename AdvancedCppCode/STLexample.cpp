#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

int main(void)
{
	std::list<int>s = { 1,2,3,4,5 };
	std::reverse(s.begin(), s.end());
	std::vector<int>ss = { 1,2,3,4,5 };
	std::reverse(ss.begin(), ss.end());

	for (int i = 0; i < s.size(); ++i)
	{
		std::cout << ss[i] << "\n";
	} 

	std::vector<int>::iterator p = ss.begin();
	while (p != ss.end())
	{
		std::cout << *p << "\n";
		++p;
	}

	for(auto& n:s)
	{
		std::cout << n << "\n";
	}

	return 0;
}