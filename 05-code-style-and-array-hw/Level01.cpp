/*
Завдання 1
Написати програму, яка копіює послідовно елементи одного масиву розміром 10 елементів у 2 масиви
розміром 5 елементів кожен.
*/

#include <iostream>

int main() {

	const int TEN_SIZE = 10;
	const int FIVE_SIZE = 5;
	int tenDigitArray[TEN_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int firstFiveDigitArray[FIVE_SIZE];
	int secondFiveDigitArray[FIVE_SIZE];
	int countSecond = 0;

	for (int countFirst = 0;  countFirst < TEN_SIZE; ++countFirst) {
		if (countFirst < 5)
			firstFiveDigitArray[countFirst] = tenDigitArray[countFirst];
		else {
			secondFiveDigitArray[countSecond] = tenDigitArray[countFirst];
			++countSecond;
		}
	}

	for (int countResult = 0;  countResult < FIVE_SIZE; ++countResult) {
		if (countResult == 0)
			std::cout << "1:" << " "  << "2:" << std::endl;

		std::cout << firstFiveDigitArray[countResult] << "  " << secondFiveDigitArray[countResult] << std::endl;
	}

	return 0;
}