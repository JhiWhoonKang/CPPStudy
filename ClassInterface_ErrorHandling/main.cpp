#include <iostream>
#include <memory>

using namespace std;

class Engine
{
public:
	auto set_oil_amount(float v)
	{
		oil_ = v;
	}

	auto get_oil_amount()const
	{
		return oil_;
	}

private:
	float oil_{};
};

class YamahaEngine :public Engine
{

};

class Boat
{
public:

private:
	shared_ptr<Engine>engine_;
	float length_{};
	
};


int main(void)
{



	return 0;
}