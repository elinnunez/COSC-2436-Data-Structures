#include <iostream>

using namespace std;

void minheapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        minheapify(arr, n, largest);
    }
}

void maxheapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);

        maxheapify(arr, n, smallest);
    }
}

void minHeapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minheapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        minheapify(arr, i, 0);
    }
}

void maxHeapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxheapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        maxheapify(arr, i, 0);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[] = {12, 11, 13, 5, 6, 7, 2, 65, 23, 54, 13, 67};
    int arr2[] = {12, 11, 13, 5, 6, 7, 2, 65, 23, 54, 13, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array: ";
    display(arr, n);

    maxHeapSort(arr, n);
    minHeapSort(arr2, n);

    cout << "Sorted:" << endl;
    cout << "Max Heap: ";
    display(arr, n); // 67 65 54 23 13 13 12 11 7 6 5 2
    cout << "Min Heap: ";
    display(arr2, n); // 2 5 6 7 11 12 13 13 23 54 65 67

    return 0;
}