#include <iostream>
#include <complex>

int main(void)
{
#pragma region complex 간단 입출력
	std::complex<double> c1(1, 0);
	std::cout << c1 << std::endl;
	std::cout << c1.real() << std::endl;
	std::cout << c1.imag() << std::endl;

	// 예시 출력
	//(1, 0)
	//	1
	//	0
#pragma endregion

#pragma region complex 삼각 함수 예제
	std::complex<double> c2 = sin(c1);
	std::cout << c2 << std::endl;
	// 예시 출력
	// (0.841471,0)

	/*std::complex<int> c3(1, 0);
	std::cout << c3 << std::endl;

	std::complex<int> c4 = sin(c3);
	std::cout << c4 << std::endl;*/
#pragma endregion

#pragma region literals
	using namespace std::complex_literals;

	std::complex<float> c5(3);		//(3,0)
	std::complex<float> c6(3, 1);	//(3,1)
	std::complex<float> c7(3if);	//(0,3)
	std::cout << "c5: " << c5 << std::endl;
	std::cout << "c6: " << c6 << std::endl;
	std::cout << "c7: " << c7 << std::endl;
	// 예제 출력
	//c5: (3, 0)
	//c6 : (3, 1)
	//c7 : (0, 3)
#pragma endregion

	return 0;
}