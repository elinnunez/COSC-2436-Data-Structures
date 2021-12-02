#include <iostream>
#include <random>

using namespace std;

void removeRandIndex(int *arr, int length, int index)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> ran(0, length - 1);
    if (length == 1)
    {
        cout << "Removing last element at arr[0]: " << arr[0] << endl;
        arr[0] = arr[0 + 1];
        cout << "Array is empty" << endl;
    }
    else
    {
        cout << "Array before index removal: ";
        cout << "[";
        for (int i = 0; i < length; i++)
        {
            if (i == length - 1)
            {
                cout << arr[i] << "]" << endl;
            }
            else
            {
                cout << arr[i] << ",";
            }
        }
        cout << "Removing arr[" << index << "]: " << arr[index] << endl;
        for (int i = index; i <= length; i++)
        {
            arr[i] = arr[i + 1];
        }

        length -= 1;
        cout << "Array after index removal: ";
        cout << "[";
        for (int i = 0; i < length; i++)
        {
            if (i == length - 1)
            {
                cout << arr[i] << "]" << endl;
                ;
            }
            else
            {
                cout << arr[i] << ",";
            }
        }

        index = ran(gen);

        removeRandIndex(arr, length, index);
    }
}

int main()
{

    random_device rd;
    mt19937 gen(rd());

    int length;

    cout << "Enter length of your array: ";

    cin >> length;

    uniform_int_distribution<> ran(0, length);

    int *arr = new int[length];

    int cur;

    for (int i = 0; i < length; i++)
    {
        cout << "Enter you value: ";
        cin >> cur;
        arr[i] = cur;
    }

    int ranIndex = ran(gen);

    removeRandIndex(arr, length, ranIndex);

    // cout << "[";
    // for (int i = 0; i < length; i++)
    // {
    //     if (i == length - 1)
    //     {
    //         cout << arr[i] << "]" << endl;
    //         ;
    //     }
    //     else
    //     {
    //         cout << arr[i] << ",";
    //     }
    // }

    delete[] arr;

    return 0;
}