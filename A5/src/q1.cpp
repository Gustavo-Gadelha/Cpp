#include <iostream>

using namespace std;

int main() {
    int number = 15;
    int *number_ptr = &number;

    double decimal = 5.5;
    double *decimal_ptr = &decimal;

    char character = 'A';
    char *character_ptr = &character;

    cout << "Antes" << endl;
    cout << "O valor de number eh: " << number << endl;
    cout << "O valor de decimal eh: " << decimal << endl;
    cout << "O valor de character eh: " << character << endl;

    *number_ptr = 5;
    *decimal_ptr = 1.2;
    *character_ptr = 'X';

    cout << endl << "Depois" << endl;
    cout << "O valor de number eh: " << number << endl;
    cout << "O valor de decimal eh: " << decimal << endl;
    cout << "O valor de character eh: " << character << endl;

    return 0;
}