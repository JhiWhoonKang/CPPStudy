#include <iostream>
#include <iterator>

int main(void)
{
	std::ostreambuf_iterator<char>p(std::cout);	// wchar_t
	*p = 65;	// ASCII 코드로 인식해서 'A'로 출력

	std::cout << 65;	// 65 출력
	std::streambuf* buf = std::cout.rdbuf();
	buf->sputc(65);		// 'A' 출력

	std::ostream_iterator<int>p1(std::cout, ",");
	*p1 = 10;	// cout << 10 << ","

	//std::ostreambuf_iterator<char> p2(std::cout);
	std::ostreambuf_iterator<char> p2(std::cout.rdbuf());
	*p2 = 'A';	// streambuf->sputc('A')

	std::ostreambuf_iterator<wchar_t> p3(std::wcout.rdbuf());
	*p3 = L'A';

	return 0;
}