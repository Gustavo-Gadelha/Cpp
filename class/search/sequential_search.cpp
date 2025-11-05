#include <iostream>

using namespace std;

void sequential_search(int arr[], int& search, int start, int end) {
	bool found = false;
	
	for (int i = start; i < end; ++i) {
		if (arr[i] == search) {
			found = true;
			cout << "Found " << search << " at index " << i << endl;
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
		sequential_search(arr, i, 0, size);	
	}
	
    return 0;
}
