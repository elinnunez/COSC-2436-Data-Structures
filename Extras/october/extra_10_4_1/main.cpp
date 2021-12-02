#include <iostream>
#include "dacqueue.h"
#include <string>

using namespace std;

int main()
{

    fstream myfile ("test.txt");

    if(!myfile.is_open()) {
        return -1;
    }

    DACQueue cargo(4);

    while(!myfile.eof()) {
        string num;
        getline(myfile, num);

        if(num.length() == 0) {
            continue;
        } else {
            cargo.enqueue(stoi(num));
        }
    }

    cout << "Original Queue: " << endl;
    cargo.printQueue();
    cout << "---------------------------" << endl;
    
    int iteration = 1;
    int total = 0;

    while(!cargo.isEmpty()) {
        int curTotal = 0;
        int cargosize = cargo.getQSize();
        for(int i = 0; i < cargosize; i++) {
            int temp = cargo.getFront()-3;
            cargo.dequeue();
            if(temp <= 0) {
                // continue;
                curTotal+= (temp+3);
            } else {
                cargo.enqueue(temp);
                curTotal+=3;
            }
        }
        cout << "Iteration " << iteration << ": " << endl;
        cargo.printQueue();
        cout << "Cur Iteration Total: " << curTotal << endl;
        total += curTotal;
        cout << "Current Accumulation of Totals: " << total << endl;
        iteration++;
    }

    return 0;
}