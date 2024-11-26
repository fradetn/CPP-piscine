#pragma once

// #include <cstdint>
#include <string>
#include <iostream>

typedef unsigned int * uintptr_t;

typedef struct s_Data
{
	std::string name;
	int age;
}	Data;


class Serializer
{
private:
	Serializer(/* args */);
	Serializer(Serializer const & src);
	Serializer &operator=(Serializer const &rhs);
public:
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
