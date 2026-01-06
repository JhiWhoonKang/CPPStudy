#include <iostream>
#include <list>

template<typename T>class List
{
public:
	List(int sz, T initValue) {}
};

int main(void)
{
	List<int>s1(10, 0);
	List s2(10, 0);	//C++17 บฮลอ OK
	std::list<int>s3 = { 1,2,3 };
	std::list s4 = { 1,2,3 };	//C++17 style
}