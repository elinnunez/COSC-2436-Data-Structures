#include <iostream>

using namespace std;

void maxheapify(int arr[], int n, int i)
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

        maxheapify(arr, n, largest);
    }
}

void minheapify(int arr[], int n, int i)
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

        minheapify(arr, n, smallest);
    }
}

void minHeapSort(int arr[], int n)
{
    // Builds a max heap
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

void maxHeapSort(int arr[], int n)
{
    // Builds a min heap
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

void maxDeleteElt(int arr[], int &size) {
    swap(arr[0], arr[size-1]);
    size--;
    maxheapify(arr, size, 0);
}

void minDeleteElt(int arr[], int &size) {
    swap(arr[0], arr[size-1]);
    size--;
    minheapify(arr, size, 0);
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
    int n2 = n;

    cout << "Unsorted Array: ";
    display(arr, n);

    maxHeapSort(arr, n); // builds min heap and sorts by descending order
    minHeapSort(arr2, n2); // builds max heap and sorts by ascending order

    cout << "Sorted:" << endl;

    cout << "Sorted Heap Descending: ";
    display(arr, n); // 67 65 54 23 13 13 12 11 7 6 5 2
    maxDeleteElt(arr, n);
    display(arr, n); // 65 23 54 11 13 13 12 2 7 6 5 

    cout << "Sorted Heap Ascending: ";
    display(arr2, n2); // 2 5 6 7 11 12 13 13 23 54 65 67
    minDeleteElt(arr2, n2);
    display(arr2, n2); // 5 7 6 13 11 12 13 67 23 54 65

    return 0;
}