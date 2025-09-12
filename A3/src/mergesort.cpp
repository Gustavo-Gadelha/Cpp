#include <iostream>

using namespace std;

constexpr int NAME_LENGTH = 20;

bool lesser_than(const char name[], const char other[]) {
    int i = 0;
    while (name[i] != '\0' && other[i] != '\0') {
        if (name[i] != other[i]) {
            return name[i] < other[i];
        }
        i++;
    }

    return name[i] < other[i];
}

void copy_from(const char from[], char to[]) {
    int i = 0;
    while (from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}


void sub_arr(char arr[][NAME_LENGTH], char dest[][NAME_LENGTH], const int start, const int end) {
    int k = 0;
    for (int j = start; j < end; ++j, ++k) {
        copy_from(arr[j], dest[k]);
    }
}

void merge(char arr[][NAME_LENGTH], const int left, const int middle, const int right) {
    const int left_size = middle - left;
    const int right_size = right - middle;

    char left_arr[left_size][NAME_LENGTH];
    char right_arr[left_size][NAME_LENGTH];

    sub_arr(arr, left_arr, left, middle);
    sub_arr(arr, right_arr, middle, right);

    int i = 0;
    int j = 0;
    int k = left;

    while (i < left_size && j < right_size) {
        if (lesser_than(left_arr[i], right_arr[j])) {
            copy_from(left_arr[i], arr[k]);
            ++i;
        } else {
            copy_from(right_arr[j], arr[k]);
            ++j;
        }
        ++k;
    }

    while (i < left_size) {
        copy_from(left_arr[i], arr[k]);
        ++k;
        ++i;
    }

    while (j < right_size) {
        copy_from(right_arr[j], arr[k]);
        ++j;
        ++k;
    }
}

void merge_sort(char arr[][NAME_LENGTH], const int start, const int end) {
    if (end - start <= 1) {
        return;
    }

    const int middle = (start + end) / 2;

    merge_sort(arr, start, middle);
    merge_sort(arr, middle, end);
    merge(arr, start, middle, end);
}

int main() {
    char names[20][NAME_LENGTH] = {
        "Maria", "Bruna", "Alberto", "Joao", "Carlos",
        "Ana", "Fernanda", "Ricardo", "Beatriz", "Paulo",
        "Juliana", "Marcos", "Gabriel", "Camila", "Rodrigo",
        "Patricia", "Lucas", "Vanessa", "Felipe", "Sofia"
    };
    const int size = sizeof(names) / sizeof(names[0]);

    merge_sort(names, 0, size);

    cout << "After merge sort, the array is: " << endl;
    for (int i = 0; i < 20; i++) {
        cout << names[i] << endl;
    }

    return 0;
}
