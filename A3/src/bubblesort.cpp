#include <iostream>

using namespace std;

constexpr int NAME_LENGTH = 20;

bool greater_than(const char name[], const char other[]) {
	int i = 0;
	while (name[i] != '\0' && other[i] != '\0') {
		if (name[i] != other[i]) {
			return name[i] > other[i];
		}
		i++;
	}

	return name[i] > other[i];
}

void copy_from(const char from[], char to[]) {
	int i = 0;
	while (from[i] != '\0') {
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';
}

void swap(char name[], char other[]) {
	char temp[NAME_LENGTH];
	copy_from(name, temp);
	copy_from(other, name);
	copy_from(temp, other);
}

void bubble_sort(char arr[][NAME_LENGTH], const int size) {
	int last_unsorted = size;
	bool sorted = false;

	while (not sorted) {
		sorted = true;

		for (int j = 0; j < last_unsorted - 1; ++j) {
			if (greater_than(arr[j], arr[j + 1])) {
				swap(arr[j], arr[j + 1]);
				sorted = false;
			}
		}

		last_unsorted--;
	}
}

int main() {
	char names[20][NAME_LENGTH] = {
		"Maria", "Bruna", "Alberto", "Joao", "Carlos",
		"Ana", "Fernanda", "Ricardo", "Beatriz", "Paulo",
		"Juliana", "Marcos", "Gabriel", "Camila", "Rodrigo",
		"Patricia", "Lucas", "Vanessa", "Felipe", "Sofia"
	};
	const int size = sizeof(names) / sizeof(names[0]);

	bubble_sort(names, size);

	cout << "After bubble sort, the array is: " << endl;
	for (int i = 0; i < 20; i++) {
		cout << names[i] << endl;
	}

	return 0;
}
