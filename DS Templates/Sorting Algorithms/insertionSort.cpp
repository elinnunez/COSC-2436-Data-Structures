#include <iostream>
using namespace std;

/*
	Time Complexity:
		Best: O(n)
		Worst: O(n^2)
		Average: O(n^2)
	
	Space Complexity: O(1)
*/

// good for linked list
void insertionSort(int arr[], int size) {
	
	for(int i = 1; i < size; i++) {
		int cur = arr[i];
		int j = i-1;

		while(j >= 0 && cur < arr[j]) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = cur;
	}
}

int main() {
    int arr[10] = {5,3,8,1,9,3,0,5,6,1};

	for(int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	int size = sizeof(arr)/sizeof(arr[0]);

	insertionSort(arr, size);

	for(int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}	

	cout << endl;

    return 0;
}