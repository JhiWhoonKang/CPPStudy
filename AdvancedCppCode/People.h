#pragma once
#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	People(std::string s) :name(s) {}
	People(const People& p) :name(p.name)
	{
		std::cout << "copy" << "\n";
	}
	People(People&& p)noexcept :name(std::move(p.name))
	{
		std::cout << "move" << "\n";
	}
	People& operator=(const People& p)
	{
		name = p.name;
		std::cout << "copy=" << "\n";
		return *this;
	}
	People& operator==(const People& p) noexcept
	{
		name = std::move(p.name);
		std::cout << "move=" << "\n";
		return *this;
	}
};