#include <iostream>
#include <utility>

template<typename T1, typename T2>
struct pair
{
	T1 first;
	T2 second;
	pair(T1 f, T2 s) : first(f), second(s) {}
};

std::pair<int, double> foo()
{
	return std::pair<int, double>{1, 3.4};
}

template<typename T> void foo(T p)
{
	std::cout << p.first << ", " << p.second << std::endl;
}

template<typename T1, typename T2>
pair < T1, T2 > make_pair(const T1& a, const T2& b)
{
	return pair<T1, T2>(a, b);
}

int main(void)
{
	std::pair<int, double>p1{ 1, 3.4 };

	std::cout << p1.first << std::endl;
	std::cout << p1.second << std::endl;

	foo(p1);
	foo(std::pair<int, int>(1, 1));	//compiler가 compile할 때 1이 integer라고 알고 있는데, 저기에 int를 명시하는게 불편한다.
									//class template이기 때문에 template 인자를 반드시 보내야 함
									//이럴 땐 pair를 바로 만들어 쓰지 말고 함수 템플릿을 만들어서 사용

	std::cout << "사용자 custom make_pair" << std::endl;
	foo(make_pair(1, 1));
	foo(make_pair<int, int>(1, 1));
	std::cout << "utility make_pair" << std::endl;
	foo(std::make_pair(1, 1));
	foo(std::make_pair<int, int>(1, 1));

	return 0;
}