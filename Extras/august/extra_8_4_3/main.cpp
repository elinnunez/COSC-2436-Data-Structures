#include <iostream>
#include<vector>
#include <string>

using namespace std;

int main()
{
    int size;

    cout << "Enter size of string array: ";

    cin >> size;

    char cur[100];

    string *strArr = new string[size];

    cin.getline(cur,sizeof(cur));
    strArr[0] = cur;

    for(int i = 0; i < size; i++) {
        cin.getline(cur, sizeof(cur));
        strArr[i] = cur;
    }

    for(int i = size-1; i >= 0; i--) {
        cout << strArr[i] << endl;
    }

    delete [] strArr;

    return 0;
}