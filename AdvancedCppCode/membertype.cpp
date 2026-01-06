#include <iostream>
#include <list>
#include <vector>

#if 0
#pragma region ex1

#if 0
void print(std::vector<int>& c)
{
	int n = c.front();
	std::cout << n << "\n";
}
#endif

#if 0
template<typename T>
void print(std::vector<T>& c)
{
	T n = c.front();
	std::cout << n << "\n";
}
#endif

template<typename T>
void print(T& c)
{
	typename T::value_type n = c.front();	// tpye으로 인식
	std::cout << n << "\n";
}


int main(void)
{
	std::vector<int>v = { 1,2,3 };
	std::vector<double>v2 = { 1,2,3 };
	print(v);
	print(v2);

	return 0;
}
#pragma endregion
#endif

#pragma region ex2
template<typename T>
void sum(T first, T last)
{
	typename T::value_type s = 0;
	// ...
}
int main(void)
{
	std::list<int>s = { 1,2,3 };
	sum(s.begin(), s.end());
	return 0;
}
#pragma endregion