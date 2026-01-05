#include <iostream>
#include <bitset>
#include <string>

int main(void)
{
	std::bitset<8> b1;			//기본적으로 0으로 초기화
	std::bitset<8> b2 = 0xf0;	// 1111`0000으로 초기화
	std::bitset<8> b3 = 0b11110000;	// b로 바료 이진수 표현

	std::cout << "b1: " << b1 << std::endl;
	std::cout << "b2: " << b3 << std::endl;
	std::cout << "b3: " << b2 << std::endl;
	
	std::string s = b2.to_string();
	unsigned long n = b2.to_ulong();

	std::cout << "s: " << s << std::endl;
	std::cout << "n: " << n << std::endl;

	b1.set();
	std::cout << ".set() b1: " << b1 << std::endl;		// 1111 1111
	b1.reset();
	std::cout << ".reset() b1: " << b1 << std::endl;	// 0000 0000
	b1.set(1);
	std::cout << ".set(1) b1: " << b1 << std::endl;		// 0000 0010
	b1[3] = 1;
	std::cout << "b1[3] = 1: " << b1 << std::endl;		// 0000 1010
	b1[0].flip();
	std::cout << "b1[0].flip(): " << b1 << std::endl;	// 0000 1011

#pragma region 조사 함수
	std::cout << "========== 조사 함수 ==========" << std::endl;
	std::cout << "현재 b1: " << b1 << std::endl;
	std::cout << "b1.test(1) == 1?: ";
	if (b1.test(1) == true)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}
	std::cout << "b1[1] == 1?: ";
	if (b1[1] == true)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}
	std::cout << "b1.none()?: ";
	if (b1.none() == true)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}
	std::cout << "b1.any()?: ";
	if (b1.any() == true)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}
	int n2 = b1.count();
	std::cout << "bi.count(): " << std::endl;
#pragma endregion
#pragma region 비트 연산
	std::bitset<8> b11 = 0b00001111;
	std::bitset<8> b12 = 0b11110000;
	std::bitset<8> b13 = b11 | b12;
	std::cout << "========== 조사 함수 ==========" << std::endl;
	std::cout << "현재 b11: " << b11 << std::endl;
	std::cout << "현재 b12: " << b12 << std::endl;
	std::cout << "b11 | b12: " << b13 << std::endl;
#pragma endregion
	std::cout << sizeof(bool) << std::endl;
	return 0;
}