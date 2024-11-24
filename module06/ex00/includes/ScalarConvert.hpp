#pragma once

#include <string>
#include <iostream>

class ScalarConvert
{
private:
	ScalarConvert();
	ScalarConvert(ScalarConvert const & src);
	ScalarConvert &operator=(ScalarConvert const &rhs);
public:
	~ScalarConvert();

	static void convert(std::string const &str);
};

