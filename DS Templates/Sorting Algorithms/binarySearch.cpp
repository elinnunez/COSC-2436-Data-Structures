#include <iostream>
using namespace std;

int binSearch(int sorted_array[], int element, int left, int right) {
	 while (left <= right) 
    { 
        int middle = left+ (right - left) / 2; 
        // Check if element is present at middle position or not 
        if (sorted_array[middle] == element) 
            return middle; 
        // If element is greater, ignore left half 
        if (sorted_array[middle] < element) 
            left = middle + 1; 
        // If element is smaller, ignore right half 
        else
            right = middle - 1; 
    } 
    // if element is not present then return -1 
    return -1;
}


int recBinSearch(int arr[], int val, int left, int right) {
	int mid = left + (right -left)/2;
	if(left >= right) {
		return -1;
	}
	if(arr[mid] == val) {
		return mid;
	}
	if(arr[mid] < val) {
		left = mid + 1;
		return recBinSearch(arr, val, left, right);
	} else {
		right = mid -1;
		return recBinSearch(arr, val, left , right);
	}
	
}

int recLinSearch(int arr[], int size, int index, int value) {
	if(arr[index] == value) {
		return index;
	}

	if(index == size) {
		return -1;
	} else {
		return recLinSearch(arr, size, index+1, value);
	}
}
int main() {
    int arr[10];

	for(int i = 0; i < 10; i++) {
		arr[i] = i+1;
	}

	int size = sizeof(arr)/sizeof(arr[0]);

	// int find = recBinSearch(arr, 90, 0, size);
	int find = recLinSearch(arr, size, 0, 7);

	if(find == -1) {
		cout << "Not found" << endl;
	} else {
		cout << "Found at index: " << find << endl;
	}

	cout << size << endl;
    return 0;
}