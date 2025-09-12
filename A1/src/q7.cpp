#include <iostream>

using namespace std;

int main() {
	int soma_par = 0;
	int soma_impar = 0;
	
	for(int numero = 0; numero <= 10000; numero++) {
		if (numero > 1000) {
			break;
		}
		
		if (numero % 2 == 0) {
			soma_par += numero;
		} else {
			soma_impar += numero;
		}
	}
	
	cout << "Soma de numeros pares: " << soma_par << endl;
	cout << "Soma de numeros impares: " << soma_impar << endl;
	
	return 0;
}