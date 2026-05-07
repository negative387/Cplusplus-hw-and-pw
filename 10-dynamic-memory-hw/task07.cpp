/*
Завдання 7. Реалізуйте функцію void allocate2D(int**& matrix, int rows, int cols), що динамічно
виділяє двовимірний масив і заповнює його нулями. Напишіть парну функцію void free2D(int**& matrix,
int rows) для коректного звільнення. У main продемонструйте їх роботу.
*/

#include <iostream>

void allocate2D(int**& matrix, int rows, int cols);
void free2D(int**& matrix,int rows);
void printMatrix(int** matrix, int rows, int cols);


int main() {
    const int ROWS = 3;
    const int COLS = 4;
    int** matrix = nullptr;

    allocate2D(matrix,ROWS,COLS);
    printMatrix(matrix, ROWS, COLS);
    free2D(matrix, ROWS);

    return 0;
}

void allocate2D(int**& matrix, int rows, int cols) {

    matrix = new int*[rows];

    for (int count = 0; count < rows; ++count) {
        matrix[count] = new int[cols];

        for (int countC = 0; countC < cols; ++countC)
            matrix[count][countC] = 0;
    }
}

void free2D(int**& matrix,int rows) {

    for (int indexR = 0; indexR < rows; ++indexR)
        delete[] matrix[indexR];

    delete[] matrix;
    matrix = nullptr;
}

void printMatrix(int** matrix, int rows, int cols) {

    for (int printR = 0; printR < rows; ++printR){

        for (int printC = 0; printC < cols; ++printC)
            std::cout << matrix[printR][printC] << " ";

        std::cout << std::endl;
    }
}