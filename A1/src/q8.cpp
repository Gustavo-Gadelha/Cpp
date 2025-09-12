#include <iostream>

using namespace std;

int main() {
	int n = 10;
	int fibonacci[n];
	
	int anterior = 0; 
	int atual = 1;
	
	for(int i = 0; i < n; i++) {
		fibonacci[i] = anterior;
		
		int proximo = anterior + atual;
		anterior = atual;
		atual = proximo;
		
		cout << fibonacci[i] << " ";
	}
	
	return 0;
}