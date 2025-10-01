#include <iostream>

using namespace std;

int main() {
    int number = 20;
    int other = 20;

    if (&number > &other) {
        cout << "O endereco de number (" << &number << ") eh maior que o endereco de other (" << &other << ")" << endl;
    } else {
        cout << "O endereco de number (" << &number << ") eh menor que o endereco de other (" << &other << ")" << endl;
    }

    return 0;
}