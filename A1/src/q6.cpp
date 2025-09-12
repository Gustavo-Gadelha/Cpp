#include <iostream>

using namespace std;

int main() {
	for(int numero = 1; numero < 100; numero++) {
		bool primo = numero > 1;
		
		for (int j = 2; j < numero; j++) {
			if (numero % j == 0) {
				primo = false;
				break;				
			}
		}
		
		if (primo) {
			cout << "O numero " << numero << " e primo" << endl;
		} else {
			cout << "O numero " << numero << " nao e primo" << endl;
		}
	}
	
	return 0;
}