#include <iostream>

using namespace std;

void shellSort(int arr[], int size) {
    for(int gap = size/2; gap > 0; gap/=2) {
        for(int i = gap; i < size; i++) {
            for(int j = i - gap; j >= 0; j-=gap) {
                if(arr[j] < arr[j+gap]) {
                    break;
                } else {
                    swap(arr[j], arr[j+gap]);
                }
            }
        }
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

    int ranArr[10] = {14,62,41,74,85,14,65,24,56,45};
    int size = sizeof(ranArr)/sizeof(ranArr[0]);

    cout << "Before Shell Sort: ";
    display(ranArr, size);

    shellSort(ranArr, size);

    cout << "After Shell Sort: "; // 14 14 24 41 45 56 62 65 74 85
    display(ranArr, size);

    return 0;
}