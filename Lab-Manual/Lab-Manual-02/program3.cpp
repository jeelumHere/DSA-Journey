#include <iostream>

using namespace std;

void selection(int array[], int size) {
	int temp, j;
	int i = 0;

	while (i < size - 1) {
		j = i + 1;
		while (j < size) {
			if (array[i] > array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}
void display(const int array[], int size) {
	for (int index = 0; index < size; ++index) {
		cout << array[index] << ' ';
	}
	cout << '\n';
}
int main() {
	int size;
	cout << "Enter the size of the array: ";
	cin >> size;

	if (size <= 0) {
		cout << "Array size must be positive.\n";
		return 1;
	}
	int* array = new int[size];
	cout << "Enter " << size << " integer values:\n";
	for (int index = 0; index < size; ++index) {
		cin >> array[index];
	}
	cout << "Original array: ";
	display(array, size);

	selection(array, size);

	cout << "Sorted array: ";
	display(array, size);

	delete[] array;
	return 0;
}
