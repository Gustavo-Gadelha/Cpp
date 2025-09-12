#include <iostream>

using namespace std;


void swap(int &a, int &b) {
	const int temp = a;
	a = b;
	b = temp;
}


void selection_sort(int arr[], const int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min = i;
        
        for (int j = i + 1; j < size; ++j) {
        	if (arr[j] < arr[min]) {
        		min = j;
			}
		}
		
		if (i != min) {
			swap(arr[i], arr[min]);
		}
    }
}


int main() {
	int size = 30;
    int arr[size] = {
		72, 15, 99, 3, 84, 61, 42, 28, 7, 36, 
		91, 4, 56, 63, 12, 1, 88, 25, 69, 17, 
		48, 95, 2, 33, 77, 27, 12, 74, 97, 9,
	};

    cout << "Array: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selection_sort(arr, size);

    cout << "After sorting: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
