#include <iostream>
#include <functional>

using namespace std;

typedef int (*fp4)(int, int);
using fp4_using = int(*)(int, int);

void PrintNum(int num)
{
	cout << num << "\n";
}

int Sum(int a, int b)
{
	return a + b;
}

int main(void)
{
	/*
	* 함수 포인터
	* return_type(*pointer_Name)(parameter_type1,  parameter_type2, ...)
	* 상수 함수 포인터
	* return_type(*const pointer_Name)(parameter_type1,  parameter_type2, ...)
	*/
	void(*fp)(int) = PrintNum;	// 함수 포인터
	void(* const fp2)(int) = PrintNum;		// 상수 함수 포인터
	
	cout << "함수 이름 호출: " << PrintNum << "\n";
	cout << "함수 포인터 호출: " << fp << "\n";
	cout << "상수 함수 포인터 호출: " << fp2 << "\n";

	cout << "\n";

	int num1 = 10, num2 = 20;
	int(*fp3)(int, int) = Sum;
	
	cout << "명시적 역참조: " << (*fp3)(num1, num2) << "\n";
	cout << "암시적 역참조: " << fp3(num1, num2) << "\n";

	cout << "\n";

	fp4 fp4_ = Sum;
	auto fp4_auto = Sum;
	fp4_using fp4_using = Sum;
	
	cout << "typedef 이용: " << fp4_(num1, num2) << "\n";
	cout << "auto 이용: " << fp4_auto(num1, num2) << "\n";
	cout << "using 이용: " << fp4_using(num1, num2) << "\n";

	cout << "\n";

	/*
	* function 이용 방법
	* function<return_type(parameter1, parameter2, ...)>pointer_name;
	*/
	function<int(int, int)>fp5 = Sum;

	cout << "function 이용: " << fp5(num1, num2) << "\n";

	return 0;
}