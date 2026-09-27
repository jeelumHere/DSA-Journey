#include <iostream>

using namespace std;

const int MATRIX_SIZE = 3;

void selectionSort(int* array, int size) {
	for (int current = 0; current < size - 1; ++current) {
		int smallestIndex = current;

		for (int next = current + 1; next < size; ++next) {
			if (*(array + next) < *(array + smallestIndex)) {
				smallestIndex = next;
			}
		}

		int temporary = *(array + current);
		*(array + current) = *(array + smallestIndex);
		*(array + smallestIndex) = temporary;
	}
}
void displayMatrix(int (*matrix)[MATRIX_SIZE]) {
	for (int row = 0; row < MATRIX_SIZE; ++row) {
		for (int column = 0; column < MATRIX_SIZE; ++column) {
			cout << matrix[row][column] << ' ';
		}
		cout << '\n';
	}
}
int main() {
	int matrix[MATRIX_SIZE][MATRIX_SIZE];

	cout << "Enter the 3 x 3 array:\n";
	for (int row = 0; row < MATRIX_SIZE; ++row) {
		for (int column = 0; column < MATRIX_SIZE; ++column) {
			cin >> matrix[row][column];
		}
	}
	cout << "Original array:\n";
	displayMatrix(matrix);
	selectionSort(&matrix[0][0], MATRIX_SIZE * MATRIX_SIZE);
	cout << "Sorted array:\n";
	displayMatrix(matrix);
	return 0;
}
