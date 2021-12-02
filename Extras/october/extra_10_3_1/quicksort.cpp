#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low -1;
    for(int j = low; j <= high -1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return (i+1);

};


void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void display(int arr[], int size) {

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int unSorted[10] = {4,8,5,1,7,4,6,0,2,5};

    int size = sizeof(unSorted)/sizeof(unSorted[0]);

    cout << "Unsorted Array: ";
    display(unSorted, size);

    quickSort(unSorted, 0, 9);

    cout << "Sorted Array: ";
    display(unSorted, size);

    return 0;
}