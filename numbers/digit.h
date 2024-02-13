#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <conio.h>
#include <cstdlib>

class Digit {
public:
	Digit() {}
	~Digit() {}
	Digit(const size_t _number) : number(_number) {}
	size_t getDigit() const;
	void setDigit(const size_t &_number);
	void outputDigit() const;
private:
	size_t number = 0;
};
