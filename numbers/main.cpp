#include "field.h"

int main() {
	try {
		size_t val = 0;
		while (true) {
			std::cout << "Enter a number bigger than 1 for the square matrix field size: ";
			std::cin >> val;
			if (std::cin.fail() || val < 2) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
				break;
		}
		system("cls");
		Field game;
		game.setSquare(val);
		game.startGame();
	}
	catch (const std::exception &ex) {
		std::cout << "\n" << ex.what() << std::endl;
	}
	return 0;
}
