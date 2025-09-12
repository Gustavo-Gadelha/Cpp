#include <iostream>

using namespace std;

int main() {
	const string musicas[11] = {
	    "MEIO DIA",
	    "ROCK NO SERTAO",
	    "SAGA DE UM VAQUEIRO",
	    "BOTA PEGADO PAREA",
	    "PONTO FINAL",
	    "LUZ CAMERA ACAO",
	    "TOMA CONTA DE MIM",
	    "OLHA PRO CEU",
	    "OLHINHOS DE FOGUEIRA",
	    "RANCHEIRA",
	    "AVOANTE"
	};
	
	
	int primeiro;
	cout << "Aperte o primeiro botao: ";
	cin >> primeiro;
	
	if (primeiro < 0 || primeiro > 5) {
		cout << "Opcao invalida" << endl;
		return 0;
	}
	
	int segundo;
	cout << "Aperte o segundo botao: ";
	cin >> segundo;

	if (segundo < 0 || segundo > 5) {
		cout << "Opcao invalida" << endl;
		return 0;
	}
	
	int indice = primeiro + segundo;
	
	cout << "Agora tocando: " << indice << ". " << musicas[indice] << endl;
	
	return 0;
}