#include <iostream>
#include <algorithm>

struct Point
{
	int x, y;
};

int main(void)
{
	Point p1, p2;
	std::min(p1, p2);	// < 또는 > 연산


	int n1 = std::min(1, 2);
	int n2 = std::min({ 1,2,3,4,5 });	// cpp11 initailizer list



	return 0;
}