#include <iostream>

using namespace std;


void swap(int &a, int &b) {
	const int temp = a;
	a = b;
	b = temp;
}


void show_arr(int arr[], int size) {
	for(int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void bubblesort(int arr[], const int size) {
	int last_unsorted = size;
    bool sorted = false;
    
    while (not sorted) {
		sorted = true;

        for (int j = 0; j < last_unsorted - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                sorted = false;
            }
        }
        
        last_unsorted--;
    }
}


int main() {
	int size = 30;
    int arr[size] = {
		72, 15, 99, 3, 84, 61, 42, 28, 7, 36, 
		91, 4, 56, 63, 12, 1, 88, 25, 69, 17, 
		48, 95, 2, 33, 77, 27, 12, 74, 97, 9,
	};

    cout << "Before sorting: " << endl;
	show_arr(arr, size);
    cout << endl;

    bubblesort(arr, size);

    cout << "After sorting: " << endl;
	show_arr(arr, size);
    cout << endl;

    return 0;
}
