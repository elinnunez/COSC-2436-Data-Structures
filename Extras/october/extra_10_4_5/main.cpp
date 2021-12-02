#include <iostream>

using namespace std;

int hashFunc(int x)
{
    return x % 10;
}

int linearProbing(int arr[], int size, int x)
{
    int index = hashFunc(x);

    if (arr[index] == -1)
    {
        arr[index] = x;
    }
    else
    {
        int curI = index;
        if (index == size - 1)
        {
            curI = -1;
        }
        for (int i = curI + 1; i != index; i++)
        {
            if (arr[i] == -1)
            {
                arr[i] = x;
                break;
            }
            if (arr[i] == size - 1)
            {
                i = -1;
            }
        }
    }
}

bool search(int arr[], int size, int key)
{
    int index = hashFunc(key);
    bool flag = false;

    if (arr[index] == key)
    {
        cout << "True" << endl;
        return true;
    }
    else
    {
        int curI = index;

        if (index == size - 1)
        {
            curI = -1;
        }
        curI += 1;

        while (curI != index && arr[curI] != key)
        {
            if (curI == size - 1)
            {
                curI = -1;
            }
            curI += 1;
        }

        if(arr[curI] == key) {
            cout << "True" << endl;
            return true;
        } else {
            cout << "False" << endl;
            return false;
        }
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    // int randArr[15] = {25,17,63,57,65,14,48,6,15,94,73,2,84,51,23};
    int tempArr[10] = {26, 30, 45, 23, 25, 43, 74, 19, 29, 22};
    // int size = sizeof(randArr)/sizeof(randArr[0]);
    // int size = sizeof(smallArr)/sizeof(smallArr[0]);

    int table[10];
    for (int i = 0; i < 10; i++)
    {
        table[i] = -1;
    }

    cout << "Unprobed Array: ";
    display(tempArr, 10);

    for (int i = 0; i < 10; i++)
    {
        linearProbing(table, 10, tempArr[i]);
    }

    cout << "Probed Array: ";
    display(table, 10);

    search(table, 10, 55);
    search(table, 10, 29);

    return 0;
}