#include <iostream>
#include <list>
#include <algorithm>
#include <forward_list>

template<typename ITER>
class Reverse_iterator
{
	ITER iter;	// list의 일반 반복자. ++ => 
public:
	Reverse_iterator(ITER i)
	{
		iter = i;
		--iter;
	}
	Reverse_iterator& operator++()
	{
		--iter;
		return *this;
	}
	typename ITER::value_type operator*()
	{		
		return *iter;
	}
	// ==, !=, --(++)
};

int main()
{
#if 0	// reverse_iterater 간단 예
	std::list<int>s = { 1,2,3,4,5,6,7,8,9,10 };
	auto p1 = std::begin(s);
	auto p2 = std::end(s);

	std::reverse_iterator<std::list<int>::iterator>p3(p2);	// p3와 p2는 다른 객체. p3가 바뀐다고 p2가 바뀌지 않는다. 참조 관계 x
	std::reverse_iterator<std::list<int>::iterator>p4(p1);

	auto ret1 = std::find(p1, p2, 3);
	auto ret2 = std::find(p3, p4, 3);

	//++p3;	// --p2와 동일하게 동작

	std::cout << *p3 << "\n";	//10	
	++p3;
	std::cout << *p3 << "\n";	//9
	++p3;
	std::cout << *p3 << "\n";	//8
	--p2;
	std::cout << *p2 << "\n";	//10

	//auto ret = std::find(p1, p2, 3);
	//auto ret = std::find(p2, p1, 3);	// error
#endif

#if 0
	std::list<int>s = { 1,2,3,4,5,6,7,8,9,10 };
	auto p1 = std::begin(s);
	auto p2 = std::end(s);

	// 1. 기존 반복자를 가지고 생성
	std::reverse_iterator<std::list<int>::iterator>r1(p2);
	auto r2 = std::make_reverse_iterator(p2);

	// 2. 컨테이너에서 직접 꺼내기
	auto r3 = s.rbegin();
	auto r4 = rbegin(s);
	auto r5 = s.rend();
	auto r6 = rend(s);

	std::cout << *r1 << "\n";
	std::cout << *r2 << "\n";
	std::cout << *r3 << "\n";
	std::cout << *r4 << "\n";
	//std::cout << *r5 << "\n";
	//std::cout << *r6 << "\n";

#endif

#if 01	// iterator 종류 정리
	std::list<int>s = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>::iterator p1 = std::begin(s);
	std::list<int>::reverse_iterator p2 = std::rbegin(s);
	std::list<int>::const_iterator p3 = std::cbegin(s);
	//*p3=10;	// error

	std::list<int>::const_reverse_iterator p4 = std::crbegin(s);

	auto p1 = std::begin(s);
	auto  p2 = std::rbegin(s);
	auto  p3 = std::cbegin(s);
	//*p3=10;	// error
	
	auto p4 = std::crbegin(s);

	// 주의
	std::forward_list<int>s2 = { 1,2,3,4,5,6,7,8,9,10 };
	//auto p5 = std::rbegin(s2);	// error
#endif
	return 0;
}