#include <iostream>
#include <list>
#include <iterator>

#if 0
template<typename T>
std::back_insert_iterator<T>
back_insert(T& c)
{
	return std::back_inserter_iterator<T>(c);
}
#endif

#pragma region insert iterator 클래스 구현
template<typename C>
class eback_insert_iterator {
	C* container;
public:
	using iterator_category = std::output_iterator_tag;
	using value_type = void;
	using pointer = void;
	using reference = void;
	using difference_type = void;
	using container_type = C;
	explicit eback_insert_iterator(C& c) :container(std::addressof(c)) {}	//c.operator&()
	eback_insert_iterator& operator*()
	{
		return *this;
	}
	eback_insert_iterator& operator++()
	{
		return *this;
	}
	eback_insert_iterator& operator++(int)
	{
		return *this;
	}
	eback_insert_iterator& operator=(const typename C::value_type& a)
	{
		container->push_back(a);
		return *this;
	}
	eback_insert_iterator& operator=(const typename C::value_type&& a)
	{
		container->push_back(std::move(a));
		return *this;
	}
};
#pragma endregion


int main(void)
{
#pragma region insert iterator 1
#if 0
	std::list<int>s = { 1,2,3,4,5 };
	//s.push_back(10);

	//std::back_insert_iterator<std::list<int>>p(s);
	//*p = 20;	// s.push_back(20);
	int x[5] = { 10,20,30,40,50 };
	/*for (int i = 0; i < 5; ++i)
	{
		s.push_back(x[i]);
	}*/
	//std::copy(x, x + 5, p);
	std::copy(x, x + 5, std::back_inserter(s));

	for (auto& n : s)
	{
		std::cout << n << "\n";
	}
#endif
#pragma endregion

#pragma region insert iterator 2
#if 0
	int x[5] = { 1,2,3,4,5 };
	std::list<int>s = { 0,0,0,0,0 };
	// 클래스 버전
	//std::back_insert_iterator<std::list<int>>p(s);
	//std::front_insert_iterator<std::list<int>>p(s);
	std::insert_iterator<std::list<int>>p(s, ++s.begin());
	//std::copy(x, x + 5, p);
	// 생성자 버전
	//std::copy(x, x + 5, std::back_inserter(s));
	//std::copy(x, x + 5, std::front_inserter(s));
	std::copy(x, x + 5, std::inserter(s, ++s.begin()));
	for (auto& n : s)
	{
		std::cout << n << ",";	//front_insert_iterator 출력: 5,4,3,2,1,0,0,0,0,0,
								//임의 삽입 출력: 0,1,2,3,4,5,0,0,0,0,
	}
#endif
#pragma endregion

#pragma region insert iterator 구현 원리
	std::list<int>s = { 1,2 };
	eback_insert_iterator<std::list<int>>p(s);
	p = 20;		//모든 반복자는 반드시 역참조가 가능해야 한다는 규칙이 존재하기에 아래와 같이 *p로 만든다.
	*p = 30;	//(p.operator*()).opearator=(30)

	int x[2] = { 1,2 };
	std::copy(x, x + 2, p);	// ++p로 이동했을 것
	for (auto& n : s)
	{
		std::cout << n << ",";
	}
#pragma endregion


	return 0;
}