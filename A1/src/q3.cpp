#include <iostream>

using namespace std;

int main() {
	char letra;
	cout << "Digite M ou F: ";
	cin >> letra;
	
	if (letra == 'M') {
		cout << "Masculino" << endl;
	} else if (letra == 'F') {
		cout << "Feminino" << endl;
	} else {
		cout << "Sexo invalido" << endl;
	}
	
	return 0;
}