#include <iostream>

using namespace std;

int main()
{

    int size;

    cout << "Enter size of array: ";
    cin >> size;

    int *numArr = new int[size];

    int cur;

    for (int i = 0; i < size; i++)
    {
        cin >> cur;
        numArr[i] = cur;
    }

    cout << "Pairs in array that produce even products:" << endl;

    int count = 0;

    for (int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++) {
            int product = numArr[i] * numArr[j];
            if(product % 2 == 0) {
                count+=1;
                cout << "[" << numArr[i] << ","<< numArr[j] << "]" << endl;
            }
        }
    }

    if(count > 0) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    delete [] numArr;

    return 0;
}