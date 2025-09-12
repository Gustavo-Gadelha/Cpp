#include <iostream>

using namespace std;


int main() {	
	const int n = 10;
	char vector[n] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
		
	int qtd_consonants = 0;
	
	for (int i = 0; i < n; ++i) {
		switch (vector[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				break;
			default:
				qtd_consonants++;
		}
	}
	
	cout << "Quantidade de consoantes: " << qtd_consonants << endl;
	
	return 0;
} 