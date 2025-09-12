#include <iostream>

using namespace std;

int main() {
	int numero;
	cout << "Digite um numero: ";
	cin >> numero;
	
	if (numero > 0) {
		cout << "Voce digitou um numero positivo" << endl;
	} else if (numero == 0) {
		cout << "Voce digitou zero" << endl;
	} else {
		cout << "Voce digitou um numero negativo" << endl;
	}
	
	return 0;
}