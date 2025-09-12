#include <iostream>

using namespace std;

constexpr int NAME_LENGTH = 20;

bool lesser_than(const char name[], const char other[]) {
	int i = 0;
	while (name[i] != '\0' && other[i] != '\0') {
		if (name[i] != other[i]) {
			return name[i] < other[i];
		}
		i++;
	}

	return name[i] < other[i];
}

void copy_from(const char from[], char to[]) {
	int i = 0;
	while (from[i] != '\0') {
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';
}

void insertion_sort(char arr[][NAME_LENGTH], const int size) {
	char current[NAME_LENGTH];

	for (int i = 1; i < size; ++i) {
		copy_from(arr[i], current);
		int previous = i - 1;

		while (previous >= 0 and lesser_than(current, arr[previous])) {
			copy_from(arr[previous], arr[previous + 1]);
			--previous;
		}

		copy_from(current, arr[previous + 1]);
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

	insertion_sort(names, size);

	cout << "After insertion sort, the array is: " << endl;
	for (int i = 0; i < 20; i++) {
		cout << names[i] << endl;
	}

	return 0;
}
