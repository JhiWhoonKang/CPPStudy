#include <iostream>
#include <string>
#include <complex>

void foo(std::string s)
{
	std::cout << "string" << std::endl;
}
void foo(const char* s)
{
	std::cout << "char*" << std::endl;
}

int main(void)
{
	foo("hello");
	foo(std::string("hello"));
	
	//std::complex<double> c(0, 3);
}