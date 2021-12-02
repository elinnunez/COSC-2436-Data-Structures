#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void populateFile(int size, ofstream& file) {
    
    if(!file) {
        return;
    }

    stringstream ss;

    for(int i = 0; i < size; i++) {
        string randInt = to_string((rand()%100)+1);
        file << randInt << endl;
    }
}

void directMapping(int *arr, ifstream& file, int *collision) {
    if(!file.is_open()) {
        cout << "Can't Open File" << endl;
        return;
    }

    while(!file.eof()) {
        string line;

        getline(file, line);
        if(line.length() == 0) {
            continue;
        }

        int index = stoi(line)%10;

        if(arr[index] < 0) {
            arr[index] = stoi(line);
        } else {
            arr[index] = stoi(line);
            *collision+=1;
        }
    }
}

void display(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    ofstream file("nums.txt");

    populateFile(20, file);

    ifstream infile("nums.txt");

    int arr[10];
    int collision = 0;

    for(int i = 0; i < 10; i++) {
        arr[i] = -1;
    }

    directMapping(arr,infile, &collision);

    display(arr,10);

    cout << "Collisions: " << collision << endl;




    return 0;
}