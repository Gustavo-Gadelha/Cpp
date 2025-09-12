#include <iostream>

using namespace std;

int main() {
	int numero;
	cout << "Digite um numero: ";
	cin >> numero;
	
	cout << "Tabuada do " << numero << endl;
	for (int i = 0; i < 10; i++) {
		cout << numero << " x " << i << " = " << numero * i << endl;
	}
	
	return 0;
}