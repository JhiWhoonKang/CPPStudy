#include <iostream>
#include <list>
#include <vector>
#include <iterator>

#pragma region iterator 정의
#if 0
template<typename T> struct iterator_traits
{
	using value_type = typename T::value_type;
};

template<typename T> struct iterator_traits<T*>
{
	using value_type = T;
};
#endif
#pragma endregion


#if 0	// 초기
template<typename T>
typename T::value_type sum(T first, T last)
{
	//typename T::value_type s = 0;
	typename iterator_traits<T>::value_type s = 0;


	while (first != last)
	{
		s = s + *first;
		++first;
	}
	return s;
}
#endif

#if 01	// 최종 버전
template<typename T>
typename std::iterator_traits<T>::value_type sum(T first, T last)
{
	//typename T::value_type s = 0;
	//typename std::iterator_traits<T>::value_type s = 0;
	//decltype(*first)s = 0;	// 이 방법이 조심해야 하는 건 int type이 아니라 int&이기 때문에
							// decltype(*pointer_type) -> 값 타입이 아니라 참조 타입이 나옴
	typename
		std::remove_reference<decltype(*first)>::type s = 0;

	while (first != last)
	{
		s = s + *first;
		++first;
	}
	return s;
}
#endif

#if 0
template<typename T>
void foo(T a)
{
	typename T::value_type n1;
	typename std::iterator_traits<T>::value_type n2;
}
#endif

int main(void)
{
	//std::list<int>s = { 1,2,3,4,5,6,7,8,9,10 };
	//std::vector<int>s = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int s[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int n = sum(std::begin(s), std::end(s));	//기존 sum 구조로는 error
	std::cout << n << "\n";
	return 0;
}