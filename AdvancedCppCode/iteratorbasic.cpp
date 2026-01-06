#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <experimental/filesystem>
using namespace std::experimental::filesystem;

int main(void)
{
#pragma region iterator 종류

#if 0
	int x[5] = { 1,2,3,4,5 };
	int* p = x;
	*p;
	++p;

	std::list<int>s = { 1,2,3,4,5 };
	std::vector<int>s = { 1,2,3,4,5 };
	std::list<int>::iterator p2 = s.begin();
	*p2;
	++p2;

	directory_iterator f("C:\\windows");
	std::cout << *f << "\n";
	++f;
	std::cout << *f << "\n";

#endif

#pragma endregion

#pragma region 컨테이너에서 반복자 꺼내기
#if 0
	//std::list<int>s = { 1,2,3,4,5 };
	//std::vector<int>s = { 1,2,3,4,5 };
	int s[5] = { 1,2,3,4,5 };
	//std::list<int>::iterator p = s.begin();
	//auto p1 = s.begin();	//cpp11 이후
		// 진짜 배열 s[5]는 error 발생
	auto p1 = std::begin(s);	// STL 컨테이너와 배열 모두 가능
	int n = std::size(s);	// s.size();
	auto p2 = std::end(s);	// 끝 다음을 가리킴
	//*p2 = 10;// runtime error; 비교용으로만 사용할 것
#endif
#pragma endregion

#pragma region 반복자의 무효화
#if 0
	std::vector<int>v = { 1,2,3,4,5 };
	std::list<int>v = { 1,2,3,4,5 };
	auto p = std::begin(v);
	v.resize(100);
	std::cout << *p << "\n";
#endif
#pragma endregion

#pragma region 반복자 구간
#if 0
	std::list<int>s1 = { 1,2,3 };
	std::list<int>s2 = { 4,5,6 };
	auto p1 = std::begin(s1);
	auto p2 = std::end(s1);
	//구간: [p1, p2)
	while (p1 != p2)
	{
		++p1;
	}
	p2 = std::end(s2);
	//이러면 유효하지 않은 구간
	std::list<int>s3;
	if(s3.empty()){}
	if (std:: begin(s3) == std::end(s3)) {}

#endif
#pragma endregion

#pragma region copy
#if 01
	int x[5] = { 1,2,3,4,5 };
	int y[5] = { 0,0,0,0,0 };
	std::list<int>s2 = { 0,0,0,0,0 };
	//// c-style
	//for (int i = 0; i < 5; ++i)
	//{
	//	y[i] = x[i];
	//}
	// stl-style
	std::copy(x, x + 5, y);
	std::copy(x, x + 5, std::begin(s2));
	for (auto& n : y)
	{
		std::cout << n << ", ";
	}
	std::cout << "\n";
	for (auto& n : s2)
	{
		std::cout << n << ", ";
	}

#endif
#pragma endregion


	return 0;
}