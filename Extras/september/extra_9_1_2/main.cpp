#include<iostream>

using namespace std;

void recSpiral(int **arr, int bottom, int right) {
    int top = 0;
    int left = 0;
    int dir = 0;

    while(top <= bottom && left <= right) {
        //if going right
        if(dir == 0) {
            for(int i = left; i < right; i++ ) {
                cout << arr[top][i] << endl;
            }
            top+=1;
        //if going down
        } else if (dir == 1) {
            for(int i = top; i < bottom; i++) {
                cout << arr[i][right-1] << endl;
            }
            right-=1;
        //if going left
        } else if(dir == 2) {
            for(int i = right-1; i >= left; i--) {
                cout << arr[bottom-1][i] << endl;
            }
            bottom-=1;
        //if going up
        } else if(dir == 3) {
           for(int i = bottom-1; i >= top; i--) {
               cout << arr[i][left] << endl;
           } 
           left+=1;
        }
        dir = (dir+1) % 4;
    }
}

int main()
{

    int row, col, temp;

    cout << "Enter number of rows: ";
    cin >> row;
    cout << endl;

    cout << "Enter number of columns: ";
    cin >> col;
    cout << endl;

    int **matrix = new int*[row];

    for(int i = 0; i < row; i++) {
        matrix[i] = new int[col];
        for(int j = 0; j < col; j++) {
            cout << "Enter number for Matrix[" << i << "][" << j << "]: ";
            cin >> temp;
            matrix[i][j] = temp;
        }
    }

    for(int i = 0; i < row; i++) {
        cout << "[";
        for(int j = 0; j < col; j++) {
            if(j == col-1) {
                cout << matrix[i][j];
            } else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << "]" << endl;
    }

    recSpiral(matrix, row, col);

    return 0;
}