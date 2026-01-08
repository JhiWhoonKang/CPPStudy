#include <iostream>
#include <iterator>
#include <list>
#include <fstream>

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
#if 01
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


	return 0;
}