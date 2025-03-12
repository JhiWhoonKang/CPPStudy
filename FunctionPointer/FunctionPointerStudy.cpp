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
	* �Լ� ������
	* return_type(*pointer_Name)(parameter_type1,  parameter_type2, ...)
	* ��� �Լ� ������
	* return_type(*const pointer_Name)(parameter_type1,  parameter_type2, ...)
	*/
	void(*fp)(int) = PrintNum;	// �Լ� ������
	void(* const fp2)(int) = PrintNum;		// ��� �Լ� ������
	
	cout << "�Լ� �̸� ȣ��: " << PrintNum << "\n";
	cout << "�Լ� ������ ȣ��: " << fp << "\n";
	cout << "��� �Լ� ������ ȣ��: " << fp2 << "\n";

	cout << "\n";

	int num1 = 10, num2 = 20;
	int(*fp3)(int, int) = Sum;
	
	cout << "����� ������: " << (*fp3)(num1, num2) << "\n";
	cout << "�Ͻ��� ������: " << fp3(num1, num2) << "\n";

	cout << "\n";

	fp4 fp4_ = Sum;
	auto fp4_auto = Sum;
	fp4_using fp4_using = Sum;
	
	cout << "typedef �̿�: " << fp4_(num1, num2) << "\n";
	cout << "auto �̿�: " << fp4_auto(num1, num2) << "\n";
	cout << "using �̿�: " << fp4_using(num1, num2) << "\n";

	cout << "\n";

	/*
	* function �̿� ���
	* function<return_type(parameter1, parameter2, ...)>pointer_name;
	*/
	function<int(int, int)>fp5 = Sum;

	cout << "function �̿�: " << fp5(num1, num2) << "\n";

	return 0;
}