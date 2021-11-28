#include <iostream>
#include <ctime>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int array[], int arraySize)
{
    long long int count = 0;
    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int j = 0; j < arraySize - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                count += 1;
            }
        }
    }
    cout << "Number of Swaps: " << count << endl;
};

void bubblesortv2(int arr[], int size)
{
    long long int count = 0;
    bool flag;
    for (int i = 0; i < size - 1; i++)
    {
        flag = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
                count += 1;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
    cout << "Number of swaps: " << count << endl;
};

int main()
{
    clock_t beg, end;

    //create interactive menu

    int choice;

    cout << "menu" << endl;
    cout << "1-bubblesort" << endl;
    cout << "2-bubblesort v2" << endl;

    cin >> choice;

    int a[100000];

    int aSize = sizeof(a) / sizeof(a[0]);

    //fill randomly;
    for (int i = 0; i < aSize; i++)
    {
        a[i] = rand() % 100;
        // cout << a[i] << " ~ ";
    }

    // int b[500000];
    int b[100000];

    int bSize = sizeof(b) / sizeof(b[0]);

    //fill randomly
    for (int i = 0; i < bSize; i++)
    {
        b[i] = rand() % 100;
        // cout << b[i] << " ~ ";
    }

    switch (choice)
    {
    case 1:
        beg = clock();
        bubblesort(a, aSize); // print # of comparisons & # of swaps;
        end = clock();
        // for(int i = 0; i < aSize; i++) {
        //     cout << a[i] << " ";
        // }
        cout << "time taken for BS: " << float(end - beg) / CLOCKS_PER_SEC << " secs" << endl;
        break;
    case 2:
        beg = clock();
        bubblesortv2(b, bSize);
        end = clock();
        // for (int i = 0; i < bSize; i++)
        // {
        //     cout << b[i] << " ";
        // }
        cout << "time take for BSv2: " << float(end - beg) / CLOCKS_PER_SEC << " secs" << endl;
        break;
    }

    return 0;
}