#include <iostream>
#include <iterator>
#include <algorithm>
#include <forward_list>

int* foo()
{
	static int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	return x;
}

int main(void)
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	std::forward_list<int>s = { 1,2,3,4,5,6,7,8,9,10 };	

	auto p1 = std::next(std::begin(s));
	auto p2 = ++std::begin(s);
	//auto p3 = ++std::begin(x);	// error
	std::advance(p1, 3);	// p1 + 3;, +가 되는 것은 임의 접근만
	std::cout << *p1 << "\n";

	std::cout << std::distance(std::begin(s), p1) << "\n";	// p1 - begin(s), -가 되는 것은 임의 접근만

	std::iter_swap(p1, std::begin(s));
	std::cout << *p1 << "\n";

	// next가 생긴 이유
	foo();
	//++foo();			// 포인터 값을 반환한다고 해도 temporaly를 ++한거여서 안 됨
	std::next(foo());	// success
	std::cout << *p2 << "\n";
	// ======	
	
	return 0;
}