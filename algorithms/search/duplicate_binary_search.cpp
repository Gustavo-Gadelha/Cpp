#include <iostream>

using namespace std;


void binary_search(int arr[], int& search, int start, int end) {
	bool found = false;
	
	while (start <= end) {
		int middle = (start + end) / 2;
		
		if (search == arr[middle]) {
			cout << "Found " << search << " at index " << middle << endl;
			found = true;
			int offset;
			
			offset = 1;
			while (search == arr[middle + offset] and middle + offset < end) {
				cout << "Found " << search << " at index " << middle + offset << endl;
				++offset;
			}
			
			offset = 1;
			while (search == arr[middle - offset] and middle - offset >= start) {
				cout << "Found " << search << " at index " << middle - offset << endl;
				++offset;
			}
			
			break;
		}
		
		if (search > arr[middle]) {
			start = middle + 1;
		} else {
			end = middle - 1;
		}
	}
	
	if (not found) {
		cout << search << " is not in the array" << endl;
	}
}


int main() {
	int size = 50;
    int arr[size];

	cout << "< Array >" << endl;
    for (int i = 0; i < size; ++i) {
    	arr[i] = 1;
        cout << arr[i] << " ";
    }
	cout << endl;
	
	for (int i = 0; i < 10; ++i) {
		cout << "Searching for value > " << i << endl;
		binary_search(arr, i, 0, size);
	}
	
    return 0;
}
