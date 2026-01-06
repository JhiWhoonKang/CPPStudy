#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <forward_list>
#include <iterator>
#include <type_traits>

#pragma region tag dispatching
#if 0
struct input_iterator_tag {};	// empty class
struct output_iterator_tag {};	// empty class
struct forward_iterator_tag :public input_iterator_tag{};
struct bidirectional_iterator_tag :public input_iterator_tag{};
struct random_access_iterator_tag :public input_iterator_tag{};

template<typename T>
class vector_iterator
{
public:
	using iterator_category = random_access_iterator_tag;
};

template<typename T>
class list_iterator
{
public:
	using iterator_category = bidirectional_iterator_tag;
};
#endif
// tag dispatching 기술 정리
// 1. 
template<typename T>
//void eadvance_imp(T& p, int n, random_access_iterator_tag)
void eadvance_imp(T& p, int n, std::random_access_iterator_tag)
{
	std::cout << "random version" << "\n";
	p = p + n;
}

template<typename T>
//void eadvance_imp(T& p, int n, input_iterator_tag)
void eadvance_imp(T& p, int n, std::input_iterator_tag)
{
	std::cout << "input version" << "\n";
	while (n--)
	{
		++p;
	}
}

template <typename T>
typename std::enable_if<std::is_same<typename T::iterator_category, std::random_access_iterator_tag>::value>::type
eadvance(T& p, int n)
{
	p = p + n;
}

template <typename T>
typename std::enable_if<!std::is_same<typename T::iterator_category, std::random_access_iterator_tag>::value>::type
eadvance(T& p, int n)
{
	while (n--)
	{
		++p;
	}
}

#if 0
template<typename T>
void eadvance(T& p, int n)
{
	/*
	while (n--)
	{
		++p;
	}
	*/
	// T::iterator_category => type 나옴
	eadvance_imp(p, n, typename T::iterator_category());
	// 또는 
	if constexpr (std::is_same<T::iterator_category, std::random_access_iterator_tag>::value)
	{
		p = p + n;
	}
	else
	{
		while (n--)
		{
			++p;
		}
	}
}
#endif
#pragma endregion

#pragma region member type
#if 0
template<typename Category,
	typename T,
	typename Distance=std::ptrdiff_t,
	typename Pointer = T*,
	typename Reference=T&>
struct iterator
{
	using iterator_category = std::forward_iterator_tag;
	using value_type = T;
	using pointer = T*;
	using reference = T&;
	using difference_type = std::ptrdiff_t;
};
// slist iterator 코드 예시
template<typename T>
class slist_iterator:
	public iterator<std::forward_iterator_tag,T>
{
	Node<T>* current = 0;
public:
	slist_iterator(Node<T>* p = 0) :current(p) {}
	slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	T& operator*()
	{
		return current->data;
	}
	bool operator==(const slist_iterator& it)
	{
		return current == it.current;
	}
	bool operator!=(const slist_iterator& it)
	{
		return current != it.current;
	}
};
#endif
#pragma endregion

#pragma region algorithm & category
template<typename InputIt, typename T>
InputIt efind(InputIt first, InputIt last, T value)
{
	while (first != last && *first != value)
	{
		++first;
	}
	return first;
}
#pragma endregion


int main(void)
{
#if 0
	std::vector<int>v = { 1,3,5,7,9,2,4,6,8,10 };	// compile success
	//std::list<int>v = { 1,3,5,7,9,2,4,6,8,10 };		// compile error
	std::sort(std::begin(v), std::end(v));

	for (auto& n : v)
	{
		std::cout << n << ", ";
	}
#endif

#if 0
	std::forward_list<int>s1 = { 1,2,3 };	// single list 자료구조(단방향)
	auto p = std::begin(s1);
	++p;	// compile success
	--p;	// compile error
#endif

#if 0
	std::list<int>s1 = { 1,2,3 };			// 양방향 자료구조
	auto p = std::begin(s1);
	++p;	// compile success
	--p;	// compile success
#endif

#if 0	// multipass
	std::list<int>s1 = { 1,2,3 };			// 양방향 자료구조
	auto i = std::begin(s1);
	int n = *i;	// 입력
	*i = 20;	// 출력

	++i;		// compile success
	i = i + 1;	// <- ++i를 2번 했을 때와 동일
				// STL에서는 이 + 연산자가 ++ 연산자보다 빠를 때만 제공
				// 그래서 LL(Linked List)은 + 연산자가 동작하지 못 한다.
#endif

#if 0	// multipass
	std::list<int>s1 = { 1,2,3 };
	auto i1 = std::begin(s1);
	auto i2 = i1;

	if (i1 == i2)
	{
		std::cout << (*i1 == *i2) << "\n";
		std::cout << (++i1 == ++i2) << "\n";
	}
#endif

#if 0	// iterator category
	std::vector<int>v = { 1,2,3,4,5,6,7,8,9,10 };
	auto p = std::find(std::begin(v), std::end(v), 5);
	std::reverse(std::begin(v), std::end(v));	// 양방향
	std::sort(std::begin(v), std::end(v));		// quick sort. 임의 접근 반복자

	std::forward_list<int>s = { 1,2,3 };
	std::reverse(std::begin(s), std::end(s));	// error

	std::list<int>s2 = { 1,2,3 };
	std::sort(std::begin(s2), std::end(s2));
	s2.sort();	//ok

	std::vector<int>v = { 1,2,3 };
	v.sort();	// error
				// 일반 함수(알고리즘) sort()를 사용하면 되기 때문
#endif

#if 0		// Tag Dispatching
	std::list<int>s = { 1,2,3,4,5,6,7,8,9,10 };
	auto p1 = std::begin(s);
	auto p2 = std::begin(s);
	// iterator p를 5칸 전진하고 싶다.
	//p = p + 5;	// 불가능. 임의접근 반복자
	//std::advance(p1, 5);
	eadvance(p1, 5);
	eadvance(p2, 5);

	std::cout << *p1 << "\n";
	std::cout << *p2 << "\n";
#endif

#if 01 algorithm & category
	int x[3] = { 1,2,3 };
	int* p = efind(x, x + 3, 2);
#endif
	return 0;
}