#include <iostream>
#include "stack.h"
#include "iftopf.h"
#include "evalif.h"
#include <string>
#include "pftoif.h"

using namespace std;

void menu()
{
    cout << "Choose Option" << endl;
    cout << "1. Infix Expression to Postfix Expression" << endl;
    cout << "2. Evaluate Infix Expression" << endl;
    cout << "3. Postfix to Infix Expression" << endl;
    cout << "4. Exit" << endl;
    cout << "* Disclaimer: Single Digits Only For InFix Expression Inputs & No Spaces *" << endl;
    cout << "-------------------------------------------" << endl;
}

int main()
{
    string sent, testcase;

    testcase = "1+2*(3^4-5)^(6+7*8)-9"; //1234^5-678*+^*+9-

    menu();
    string choice;
    cout << "Enter Choice: ";
    cin >> choice;
    cout << endl;

    string output;

    while (choice != "4")
    {
        if (choice == "1")
        {
            cout << "Enter Infix: ";
            cin >> sent;

            output = genPostFix(sent);

            cout << "Infix Expression: " << sent << endl;
            cout << "Postfix Expression: " << output << endl;
        }
        else if (choice == "2")
        {
            cout << "Enter Infix Expression to Evaluate: ";
            cin >> sent;

            int num = evalInfix(sent);

            cout << "Infix Expression: " << sent << endl;
            cout << "Evaluated Infix: " << num << endl;
        }
        else if (choice == "3")
        {
            cout << "Enter Postfix: ";
            cin >> sent;

            output = genInfix(sent);

            cout << "Postfix Expression: " << sent << endl;
            cout << "Infix Expression: " << output << endl;
        }
        else if (choice != "4")
        {
            cout << "Try Again" << endl;
        }
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == "4")
        {
            cout << "Exiting..." << endl;
        }
    }

    return 0;
}