#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    //size of left and right arrays
    int lSize = mid - left + 1;
    int rSize = right - mid;

    //initialization of both left and right arrays
    int *L = new int[lSize];
    int *R = new int[rSize];

    //fill left array
    for (int i = 0; i < lSize; i++)
    {
        L[i] = arr[left + i];
    }
    // fil right array
    for (int j = 0; j < rSize; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    //merge temp L/R arrays to real array
    while (i < lSize && j < rSize)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //if extra element in L array, add to real array
    while (i < lSize)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    //if extra element in R array, add to real array
    while (j < rSize)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // int arr[] = {6, 5, 12, 10, 9, 1};
    int addSize;
    cout << "Enter size of array to mergesort: ";
    cin >> addSize;

    int *arr = new int[addSize];
    // int size = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < addSize; i++) {
        cout << "Enter Num: ";
        cin >> arr[i];
        cout << endl;
    }

    cout << "Unsorted Array: " << endl;
    printArray(arr, addSize);

    mergeSort(arr, 0, addSize - 1);

    cout << "Sorted array: " << endl;
    printArray(arr, addSize);

    return 0;
}