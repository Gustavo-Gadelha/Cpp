#include <iostream>

using namespace std;

int binary_search_wh(int arr[], int& search, int start, int end) {
	while (start <= end) {
		int middle = (start + end) / 2;
		
		if (search == arr[middle]) {
			return middle;
		}
		
		if (search > arr[middle]) {
			start = middle + 1;
		} else {
			end = middle - 1;
		}
	}
	
	return -1;
}

int binary_search_re(int arr[], int& search, int start, int end) {
	if (start > end) {
		return -1;
	}
	
	int middle = (start + end) / 2;
	
	if (search == arr[middle]) {
		return middle;
	}
	
	if (search > arr[middle]) {
		return binary_search_re(arr, search, middle + 1, end);
	} else {
		return binary_search_re(arr, search, start, middle - 1);
	}
}


int main() {
	int size = 1000;
    int arr[size];

	cout << "< Array >" << endl;
    for (int i = 0; i < size; ++i) {
    	arr[i] = 1;
        cout << arr[i] << " ";
    }
	cout << endl;
	
	for (int i = 0; i < 10; ++i) {
		cout << "Searching for value > " << i << endl;
		cout << "Result index > " << binary_search_wh(arr, i, 0, size) << endl;	
	}
	
    return 0;
}
