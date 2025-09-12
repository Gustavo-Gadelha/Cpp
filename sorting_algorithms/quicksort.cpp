#include <iostream>

using namespace std;


void swap(int &a, int &b) {
	const int temp = a;
	a = b;
	b = temp;
}


int partition(int arr[], int left, int right) {	
	int pivot = arr[right];
	int last_unsorted = left;
	
	for (int j = left; j < right; ++j) {	
		if (arr[j] < pivot) {
			swap(arr[last_unsorted], arr[j]);
			last_unsorted++;
		}
	}
	
	if (last_unsorted != right) {
		swap(arr[last_unsorted], arr[right]);	
	}
	
	return last_unsorted;
	
}


void quicksort(int arr[], int left, int right) {
	if (left < right) {
		int pivot = partition(arr, left, right);
		quicksort(arr, left, pivot - 1);
		quicksort(arr, pivot + 1, right);
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

	quicksort(arr, 0, size - 1);

    cout << "After sorting: " << endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    cout << endl;
		
	return 0;
}