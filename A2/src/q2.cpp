#include <iostream>

using namespace std;

int main() {
	const int n = 5;
	int vector[n] = {1, 2, 3, 4, 5};
	
	int sum = 0;
	int difference = 0;
	double quocient = 1;
	
	for (int i = 0; i < n; ++i) {
		int number = vector[i];
		sum += number;
		difference -= number;
		quocient /= number;
	}
	
	cout << "Soma dos valores do vetor: " << sum << endl;
	cout << "Diferenca dos valores do vetor: " << difference << endl;
	cout << "Divisao dos valores do vetor: " << quocient << endl;
	
	return 0;
} 