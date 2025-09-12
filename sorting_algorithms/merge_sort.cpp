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


void merge(int arr[], int start, int middle, int end) {
	
	int left_size = (middle + 1) - start;
	int left_arr[left_size];
	for (int i = 0; i < left_size; ++i) {
		left_arr[i] = arr[start + i];
	}
	
	int right_size = end - middle;
	int right_arr[right_size];
	for (int i = 0; i < right_size; ++i) {
		right_arr[i] = arr[(middle + 1) + i];
	}
	
	int i = start;
	int left = 0; 
	int right = 0;
	
	while (left < left_size && right < right_size) {
		if (left_arr[left] <= right_arr[right]) {
			arr[i] = left_arr[left];
			++left;
		} else {
			arr[i] = right_arr[right];
			++right;
		}
		
		++i;
	}
	
	while (left < left_size) {
		arr[i] = left_arr[left];
		++left;
		++i;
	}
	
	while (right < right_size) {
		arr[i] = right_arr[right];
		++right;
		++i;
	}
}


void merge_sort(int arr[], int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, end);
		merge(arr, start, middle, end);
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

    merge_sort(arr, 0, size - 1);

    cout << "After sorting: " << endl;
	show_arr(arr, size);
    cout << endl;

    return 0;
}
