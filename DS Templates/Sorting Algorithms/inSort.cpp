#include <iostream>
using namespace std;

//good for linked list

void insertionSort(int arr[], int size) {
	int cur;
	
	for(int i = 1; i < size; i++) {
		int j = i-1;
		cur = arr[i];
		while(j > -1 && arr[j] > cur) {
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