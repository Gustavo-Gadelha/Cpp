#include <iostream>

using namespace std;

int main() {
	const int n = 10;
	int vector[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	for (int i = n - 1; i >= 0; --i) {
		cout << " " << vector[i];
	}
	
	return 0;
} 