#pragma once

#include "digit.h"

class Field {
public:
	Field() {}
	~Field() {}
	Field(size_t _square) : square(_square) { matrix.resize(square, std::vector<Digit>(square)); }
	void setSquare(const size_t &_square);
	size_t getSquare() const;
	void outMatrix() const;
	void startGame();
private:
	size_t square = 0;
	std::vector<std::vector<Digit>> matrix;
	bool isWin();
	void fillMatrix();
};
