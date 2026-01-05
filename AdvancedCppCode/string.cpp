#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h> // C Çì´õ
#include <string> // STL string

int main(void)
{
	
	std::string s1 = "hello";
	char s2[10];

	strcpy(s2, s1.c_str());

	std::string s3 = "3.4";
	double d = stod(s3);
	std::cout << d << std::endl;
	std::string s4 = std::to_string(d);
	std::cout << s4 << std::endl;

	return 0;
}