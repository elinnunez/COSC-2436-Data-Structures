#include <iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selSort(int arr[], int size) {
	int minIndex;

	for(int i = 0; i < size-1; i++) {
		minIndex = i;
		for(int j = i+1; j < size; j++) {
			if(arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		// if(minIndex != i) {
		// 		swap(&arr[minIndex], &arr[i]);
		// }
		swap(arr[minIndex], arr[i]);
	}
}


int main() {
    int arr[16] = {9,5,2,7,9,3,2,6,4,7,3,4,8,1,0,7};

	// for(int i = 0; i < 10; i++) {
	// 	arr[i] = i+1;
	// }

	int size = sizeof(arr)/sizeof(arr[0]);

	selSort(arr, size);

	for(int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}

	cout << size << endl;
    return 0;
}