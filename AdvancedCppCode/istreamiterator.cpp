#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>

int main(void)
{
#if 0	// istream 간단 코드
	std::istream_iterator<int>p1(std::cin);
	int n = *p1;
	std::cout << n << "\n";
#endif

#if 0	//istream vs istreambuf
	char a = 0, b = 0, c = 0;
	// x \t y \y z
	/*
	std::cin >> a;	// x
	std::cin >> b;	// y
	std::cin >> c;	// z
	*/
	a = std::cin.rdbuf()->sgetc();		// x
	//b = std::cin.rdbuf()->sgetc();	// y
	b = std::cin.rdbuf()->snextc();		// \t
	c = std::cin.rdbuf()->snextc();		// y

	std::cout << a << ", " << b << ", " << c << "\n";
#endif

#if 01
	/*
	std::istream_iterator<char>p1(std::cin);
	std::ostream_iterator<char>p3(std::cout);	

	*p3 = *p1;
	*/
	std::ifstream f("istreamiterator.cpp");
	//std::istream_iterator<char>fp1(f);	// file의 첫 번째를 가리킴
	std::istream_iterator<char>fp1(f), fp2;
	std::istreambuf_iterator<char>fp4(f), fp5;
	std::ostream_iterator<char>fp3(std::cout);
	
	//*fp3 = *fp1;
	//std::copy(fp1, fp2, fp3);	// 출력물에 white space가 없는 것 확인 가능
	std::copy(fp4, fp5, fp3);	// 출력물에 white space가 있는 것 확인 가능

#endif

	return 0;
}