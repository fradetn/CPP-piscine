#pragma once

#include <iostream>
#include <string>

class Base
{
public:
	virtual ~Base(void){}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};
