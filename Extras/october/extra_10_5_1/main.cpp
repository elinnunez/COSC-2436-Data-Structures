#include <iostream>

using namespace std;

int hash1(int x) {
    return x % 10;
}

void hashIt(int table[], int size, int key) {
    int index = hash1(key);
    if(table[index] == -1) {
        table[index] = key;
    } else {
        int oldHash = index;
        for(int i = 1; i < size; i++) {
            index = (oldHash + (i*i)) % size;
            if(table[index] == -1) {
                table[index] = key;
                break;
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
    int ranArr[10] = {45,73,26,58,45,17,32,67,31,64};
    int hashTable[10];

    for(int i = 0; i < 10; i++) {
        hashTable[i] = -1;
    }

    for(int i = 0; i < 10; i++) {
        hashIt(hashTable, 10, ranArr[i]);
    }

    cout << "Before Hash: ";
    display(ranArr, 10);

    cout << "After Hash: ";
    display(hashTable, 10);


    return 0;
}