#include <iostream>

using namespace std;

int main()
{

    const int MAX = 7;
    char *days[MAX];

    for (int i = 0; i < MAX; i++)
    {
        days[i] = new char[10];
        cout << "Enter day of the week: ";
        cin.getline(days[i], 10);
    }

    for (int i = 0; i < MAX; i++)
    {
        cout << days[i] << endl;

        int j = 0;

        while (days[i][j] != '\0')
        {
            cout << days[i][j] << endl;
            j++;
        }
    }

    return 0;
}