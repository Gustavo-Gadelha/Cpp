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


void insertion_sort(int arr[], const int size) {
	for (int i = 1; i < size; ++i) {
		int current = arr[i];
		int previous = i - 1;
		
		while(previous >= 0 and current < arr[previous]) {
			arr[previous + 1] = arr[previous];
			--previous;
		}
		
		arr[previous + 1] = current;
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

    insertion_sort(arr, size);

    cout << "After sorting: " << endl;
	show_arr(arr, size);
    cout << endl;

    return 0;
}
