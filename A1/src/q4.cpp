#include <iostream>

using namespace std;

int main() {
	int soma = 0;
	int menor = INT_MIN;
	int maior = INT_MAX;
	
	for(int numero = 0; numero < 1000; numero++) {
		soma += numero;
		
		if (numero > maior) {
			maior = numero;
		} else if (numero < menor) {
			menor = numero;
		}
	}
	
	cout << "Soma: " << soma << endl;
	cout << "Maior: " << maior << endl;
	cout << "Menor: " << menor << endl;
	
	return 0;
}