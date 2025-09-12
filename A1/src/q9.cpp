#include <iostream>

using namespace std;

int main() {
	double salario;
	cout << "Digite seu salario: ";
	cin >> salario;
	
	double percentual;
	
	if (salario <= 280) {
		percentual = 0.20;
	} else if (salario <= 700) {
		percentual = 0.15;
	} else if (salario < 1500) {
		percentual = 0.10;
	} else {
		percentual = 0.05;
	}
	
	double aumento = salario * percentual;
	
	cout << "Salario antes do reajuste: " << salario << endl;
	cout << "Percentual aplicado: " << percentual * 100 << "%" << endl;
	cout << "Valor do aumento: " << aumento << endl;
	cout << "Novo Salario apos o aumento: " << salario + aumento << endl;
	
	return 0;
}