#include <iostream>

using namespace std;

void print(int arr[4][4], int l, int r, int u, int d)
{

    if (l >= r || u >= d)
    {
        return;
    }

    for (int i = l; i < r; i++)
    {
        cout << arr[u][i] << " ";
    }
    for (int i = u+1; i < d; i++)
    {
        cout << arr[i][r - 1] << " ";
    }
    
        for (int i = r - 2; i <= l; i--)
        {
            cout << arr[d - 1][i] << " ";
        }

    for (int i = d - 2; i > u; i--)
    {
        cout << arr[i][l] << " ";
    }

    print(arr, l + 1, r - 1, u + 1, d - 1);
}

int main()
{

    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    print(arr, 0, 4, 0, 4);

    return 0;
}