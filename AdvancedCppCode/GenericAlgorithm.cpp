#include <iostream>
#include <cstring>
#include <algorithm>

template<typename T1, typename T2>
T1 efind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
	{
		++first;
	}
	//return first == last ? 0 : first;
	return first;
}

int main(void)
{
	char s[] = "abcdefg";
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	char* p = efind(s, s + 4, 'e');
	double* dp = efind(x, x + 10, 5.0);
	double* ddp = std::find(x, x + 10, 5);
	if (p == 0)
	{
		std::cout << "fail" << std::endl;
	}
	else
	{
		std::cout << "sucess: " << *p << std::endl;
	}
	if (dp == x + 10)
	{
		std::cout << "fail" << std::endl;
	}
	else
	{
		std::cout << "sucess: " << *dp << std::endl;
	}
	if (ddp == x + 10)
	{
		std::cout << "fail" << std::endl;
	}
	else
	{
		std::cout << "sucess: " << *ddp << std::endl;
	}

	return 0;
}