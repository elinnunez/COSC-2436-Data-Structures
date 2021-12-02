#include <iostream>

using namespace std;

int sum(int num) {
    int total = 0;

    for(int i = 0; i < num; i++) {
        total+=i;
    }

    return total;
}

int main() 
{
    
    int choice;
    cout<<"Enter number: ";
    cin >> choice;

    cout << sum(choice) << endl;

    return 0;
}