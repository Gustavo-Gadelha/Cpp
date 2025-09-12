#include <iostream>

using namespace std;

int main() {
	int numero;
	cout << "Digite um numero: ";
	cin >> numero;
		
	int outro;
	cout << "Digite outro numero: ";
	cin >> outro;
	
	if (numero > outro) {
		cout << "O primeiro numero e maior que o segundo" << endl;
	} else if (numero == outro) {
		cout << "Os dois numeros sao iguais" << endl;
	} else {
		cout << "O segundo numero e maior que o primeiro" << endl;
	}
	
	return 0;
}