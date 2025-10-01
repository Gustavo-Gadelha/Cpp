#include "iostream"

using namespace std;

struct Employee {
    string name;
    int age;
    char gender;
    string cpf;
    string birth_date;
    int code;

    void show() {
        cout << "Detalhes do Funcionário:" << endl;
        cout << "Nome: " << name << endl;
        cout << "Idade: " << age << endl;
        cout << "Gênero " << gender << endl;
        cout << "CPF: " << cpf << endl;
        cout << "Data de Nascimento: " << birth_date << endl;
        cout << "Código: " << code << endl;
    }
};

int main() {
    Employee emp;

    cout << "Digite o nome do funcionário: ";
    cin >> emp.name;

    cout << "Digite a idade do funcionário: ";
    cin >> emp.age;

    char gender;
    cout << "Digite o gênero do funcionário (M/F): ";
    cin >> gender;

    if (gender != 'M' && gender != 'F') {
        cout << "Gênero inválido. Deve ser 'M' ou 'F'." << endl;
        return 1;
    } else {
        emp.gender = gender;
    }

    cout << "Digite o CPF do funcionário: ";
    cin >> emp.cpf;

    cout << "Digite a data de nascimento do funcionário (DD/MM/AAAA): ";
    cin >> emp.birth_date;

    int code;
    cout << "Digite o código do funcionário (0-99): ";
    cin >> code;

    if (code < 0 || code > 99) {
        cout << "Código inválido. Deve estar entre 0 e 99." << endl;
        return 1;
    }
    else {
        emp.code = code;
    }

    emp.show();

    return 0;
}