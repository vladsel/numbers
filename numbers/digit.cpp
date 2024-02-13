#include "digit.h"

size_t Digit::getDigit() const {
	return number;
}

void Digit::setDigit(const size_t &_number) {
	number = _number;
}

void Digit::outputDigit() const {
	std::cout << "|<- " << number << " ->|\t";
}
