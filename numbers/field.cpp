#include "field.h"

void Field::setSquare(const size_t &_square) {
	square = _square;
	matrix.resize(square, std::vector<Digit>(square));
}

size_t Field::getSquare() const {
	return square;
}

void Field::fillMatrix() {
	std::random_device rd;
	std::mt19937 gen(rd());

	std::vector<size_t> randNumbers;
	for (size_t i = 0; i < square * square; i++)
		randNumbers.push_back(i);
	std::shuffle(randNumbers.begin(), randNumbers.end(), gen);

	size_t counter = 0;
	std::for_each(matrix.begin(), matrix.end(), [&randNumbers, &counter](std::vector<Digit> &row) {
		std::for_each(row.begin(), row.end(), [&randNumbers, &counter](Digit &value) {
			value.setDigit(randNumbers[counter++]);
			});
		});
}

void Field::outMatrix() const {
	for (const std::vector<Digit> &row : matrix) {
		for (const Digit &val : row) {
			if (val.getDigit() == 0)
				std::cout << "\t\t";
			else
				val.outputDigit();
		}
		std::cout << "\n\n";
	}
}

bool Field::isWin() {
	bool flag = true;
	size_t temp = square * square;
	for (const std::vector<Digit> &row : matrix) {
		for (const Digit &val : row) {
			temp--;
			if (val.getDigit() != temp) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}

void Field::startGame() {
	size_t numb = 0, idxI = 0, idxJ = 0, idxZeroI = 0, idxZeroJ = 0;
	bool flag = false;
	fillMatrix();

	while (true) {
		numb = 0, idxI = 0, idxJ = 0, idxZeroI = 0, idxZeroJ = 0;
		flag = false;
		std::cout << "What number do you want to move?\n\n\n" << std::endl;
		outMatrix();
		std::cout << "\nMake your choice from: ";

		for (long int i = 0; i < square; i++) {
			for (long int j = 0; j < square; j++)
				if (matrix[i][j].getDigit() == 0) {
					idxZeroI = i, idxZeroJ = j;
					if ((i >= 0) && (j - 1 >= 0))
						std::cout << matrix[i][j - 1].getDigit() << "  ||  ";
					if ((i - 1 >= 0) && (j >= 0))
						std::cout << matrix[i - 1][j].getDigit() << "  ||  ";
					if ((i < square) && (j + 1 < square))
						std::cout << matrix[i][j + 1].getDigit() << "  ||  ";
					if ((i + 1 < square) && (j < square))
						std::cout << matrix[i + 1][j].getDigit();

					while (true) {
						while (true) {
							std::cout << "\nInput number: ";
							std::cin >> numb;
							if (std::cin.fail()) {
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							}
							else
								break;
						}

						if (((i >= 0) && (j - 1 >= 0)) && (matrix[i][j - 1].getDigit() == numb)) {
							idxI = i;
							idxJ = j - 1;
							break;
						}
						else if ((i - 1 >= 0) && (j >= 0) && (matrix[i - 1][j].getDigit() == numb)) {
							idxI = i - 1;
							idxJ = j;
							break;
						}
						else if (((i < square) && (j + 1 < square)) && (matrix[i][j + 1].getDigit() == numb)) {
							idxI = i;
							idxJ = j + 1;
							break;
						}
						else if (((i + 1 < square) && (j < square)) && (matrix[i + 1][j].getDigit() == numb)) {
							idxI = i + 1;
							idxJ = j;
							break;
						}
					}
					flag = true;
					break;
				}
			if (flag == true)
				break;
		}
		matrix[idxZeroI][idxZeroJ] = matrix[idxI][idxJ];
		matrix[idxI][idxJ].setDigit(0);

		if (isWin()) {
			std::cout << "\n\n\n\t\t\t\t|||||||||||||||||||||||||" << std::endl;
			std::cout << "\t\t\t\t||  The game is over!  ||" << std::endl;
			std::cout << "\t\t\t\t|||||||||||||||||||||||||\n\n\n" << std::endl;
			break;
		}

		system("cls");
	}
}
