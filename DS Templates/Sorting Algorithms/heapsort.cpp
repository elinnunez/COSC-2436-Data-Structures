#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
    for(int i = n/2 -1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for(int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[] = { 12, 11, 13, 5, 6, 7, 2, 65, 23, 54, 13, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array: ";
    display(arr, n);

    heapSort(arr, n);

    cout << "Sorted Array: ";
    display(arr, n);

    return 0;
}