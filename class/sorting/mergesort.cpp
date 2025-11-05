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

void sub_arr(int arr[], int copy[], int start, int end) {
	int i = 0;
	
	for (int j = start; j < end; ++j) {
		copy[i] = arr[j];
		++i;
	}
}

void merge(int arr[], int left, int middle, int right) {	

	int left_size = middle - left;
	int left_arr[left_size];
	sub_arr(arr, left_arr, left, middle);
		
	int right_size = right - middle;
	int right_arr[right_size];
	sub_arr(arr, right_arr, middle, right);
	
	int left_index = 0;
	int right_index = 0;

	int j = left;

	while (left_index < left_size && right_index < right_size) {
		if (left_arr[left_index] < right_arr[right_index]) {
			arr[j] = left_arr[left_index];
			++left_index;
		} else {
			arr[j] = right_arr[right_index];
			++right_index;
		}
		
		++j;
	}
	
	while (left_index < left_size) {
		arr[j] = left_arr[left_index];
		++j;
		++left_index;
	}
	
	while (right_index < right_size) {
		arr[j] = right_arr[right_index];
		++j;
		++right_index;
	}
}


void merge_sort(int arr[], int start, int end) {
	if (start >= end) {
		return;
	}
	
	cout << "start: " << start << ", end: " << end << endl;
	
	int middle = (start + end) / 2;
	
	merge_sort(arr, start, middle);
	merge_sort(arr, middle + 1, end);
	merge(arr, start, middle, end);
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

    merge_sort(arr, 0, size);

    cout << "After sorting: " << endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    cout << endl;
		
	return 0;
}