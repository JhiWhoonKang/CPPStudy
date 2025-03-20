#include <iostream>

using namespace std;


void Counter()
{
	static int cnt;
	++cnt;
	cout << "Current cnt: " << cnt << "\n";
}

class SoSimple
{
private:
	static int simObjCnt;
public:
	SoSimple()
	{
		++simObjCnt;
		cout << simObjCnt << "¹øÂ° SoSimple °´Ã¼" << "\n";
	}
};

int SoSimple::simObjCnt = 0;

class CountryArea
{
public:
	const static int RUSSIA = 1;
	const static int CANADA = 2;
	const static int CHINA = 3;
	const static int SOUTH_KOREA = 4;

};
int main(void)
{
#if 0
	for (int i = 0; i < 10; ++i)
	{
		Counter();
	}
#endif
#if 0
	SoSimple sim1;
	SoSimple sim2;
	SoSimple sim3;
#endif
#if 01
	cout << "Russia: " << CountryArea::RUSSIA << "\n";
	cout << "CANADA: " << CountryArea::CANADA<< "\n";
	cout << "CHINA: " << CountryArea::CHINA << "\n";
	cout << "SOUTH KOREA: " << CountryArea::SOUTH_KOREA << "\n";
#endif


	return 0;
}