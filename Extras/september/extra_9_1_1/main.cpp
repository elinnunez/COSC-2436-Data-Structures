#include <iostream>

using namespace std;

int iFact(int n) {
    int total = 1;
    for(int i = 1; i <= n; i++) {
        total = i * total;
    }

    return total;
}

int rFact(int n) {
    if(n <= 1) {
        return 1;
    } else {
        return n * rFact(n-1);
    }
}

void menu()
{
    cout << "Factorial Algorithm" << endl;
    cout << "1: Iterative Function" << endl;
    cout << "2: Recursive Function" << endl;
    cout << "3: Exit" << endl;
}

int main()
{
    int choice;

    menu();
    cout << "Enter your choice: ";
    cin >> choice;

    int numInput;


    //should have an exception for inputs other than integers
    while (choice != 3)
    {   
        cout << "Enter a number you want to use factorial on: ";
        cin >> numInput;

        if (choice == 1)
        {
            cout <<"Iterative" << endl;
            cout << iFact(numInput) << endl;
        }
        else if (choice == 2)
        {
            cout<<"Recursive" << endl;
            cout << rFact(numInput) << endl;
        } else {
            cout << "Invalid Choice, Try Again" << endl;
        }
        menu();
        cout << "Enter your choice: ";
        cin >> choice;   
    }

    return 0;
}