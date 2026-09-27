#include <iostream>

using namespace std;

const int MATRIX_SIZE = 3;
const int ELEMENT_COUNT = MATRIX_SIZE * MATRIX_SIZE;

void inputMatrix(int* matrix) {
	cout << "Enter the 3 x 3 array:\n";
	for (int index = 0; index < ELEMENT_COUNT; ++index) {
		cin >> *(matrix + index);
	}
}

void selectionSort(int* matrix) {
	for (int current = 0; current < ELEMENT_COUNT - 1; ++current) {
		int smallest = current;

		for (int index = current + 1; index < ELEMENT_COUNT; ++index) {
			if (*(matrix + index) < *(matrix + smallest)) {
				smallest = index;
			}
		}

		if (smallest != current) {
			int temporary = *(matrix + current);
			*(matrix + current) = *(matrix + smallest);
			*(matrix + smallest) = temporary;
		}
	}
}

void displayMatrix(const int* matrix) {
	for (int index = 0; index < ELEMENT_COUNT; ++index) {
		cout << *(matrix + index) << ' ';
		if ((index + 1) % MATRIX_SIZE == 0) {
			cout << '\n';
		}
	}
}

int main() {
	int matrix[MATRIX_SIZE][MATRIX_SIZE];
	int* matrixPointer = &matrix[0][0];

	inputMatrix(matrixPointer);

	cout << "Original array:\n";
	displayMatrix(matrixPointer);

	selectionSort(matrixPointer);

	cout << "Sorted array:\n";
	displayMatrix(matrixPointer);
	return 0;
}
