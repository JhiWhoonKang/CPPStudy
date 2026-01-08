#include <iostream>
#include <iterator>
#include <list>
#include <fstream>

template<typename T, typename CharT=char, typename Traits=std::char_traits<CharT>>
class eostream_iterator
{
	//std::ostream* stream;	// 실제로는 ostream 클래스는 아니고 basic_stream이 맞다.
	std::basic_ostream<CharT,Traits>* stream;	// char만 받으면 안되니까 template 만들기
	const CharT* delimiter;
public:

	using iterator_category = std::output_iterator_tag;
	using value_type = void;
	using pointer = void;
	using reference = void;
	using difference_type = void;

	using char_type = CharT;
	using traits_type = Traits;
	using ostream_type = std::basic_ostream<CharT, Traits>;

	eostream_iterator(std::ostream& os, const CharT* const deli = 0) :stream(&os), delimiter(deli) {}

	eostream_iterator& operator*()
	{
		return *this;
	}
	eostream_iterator& operator++()
	{
		return *this;
	}
	eostream_iterator& operator++(int)
	{
		return *this;
	}
	eostream_iterator& operator=(const T& v)
	{
		*stream << v;
		if (delimiter != 0)
		{
			*stream << delimiter;
		}
		return *this;
	}
};

int main(void)
{
#pragma region ostream cout stream 출력
#if 0
	int n = 10;
	std::cout << n << "\n";
	std::ostream_iterator<int> p(std::cout, ", ");
	*p = 20;	// cout << 20 << ", "
	*p = 30;	// cout << 30 << ", "

	std::list<int>s = { 1,2,3 };
	std::copy(std::begin(s), std::end(s), p);

	//std::fill_n(std::begin(s), 3, 0);
	std::fill_n(p, 3, 0);	// 0, 0, 0
#endif
#pragma endregion

#pragma region ostream file 출력
#if 0
	//std::ostream_iterator<int>p(std::cout, ", ");
	std::ostream_iterator<int>p(std::cout);	// 2번째 인자 없으면, NULL 문자로 구분
											// 출력: 2030
	*p = 20;
	++p;	// copy 등을 위해 제공되긴 하지만, no - operation. 하는 것은 없다.
	*p = 30;	//((p.operator*()).operator=(30)

	std::ofstream f("a.txt");
	std::ostream_iterator<int>fp(f, ", ");
#endif
#pragma endregion

#pragma region ostream iterator 구현
	//eostream_iterator<int>p(std::cout, ",");
	eostream_iterator<int>p(std::cout, ",");
	*p = 10;	// (p.operator*()).operator=(10);
#pragma endregion

	return 0;
}