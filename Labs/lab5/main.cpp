#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);

    string infilename = am.get("input");
    string outfilename = am.get("output");

    ifstream infile(infilename);
    ofstream outfile(outfilename);

    // ifstream infile("input1.txt");
    // ofstream outfile("output1.txt");

    if (!infile.is_open())
    {
        cout << "File isn't open" << endl;
        return 1;
    }

    map<string, int> table;

    string line;

    getline(infile, line); // the length of list... not needed with my implementation
    getline(infile, line); // the list of words separated by spaces

    string temp;
    int pos = 0;

    while ((pos = line.find(" ")) != string::npos)
    {
        temp = line.substr(0, pos);
        table[temp]++;
        line.erase(0, pos + 1); // the 1 is the length of the space == 1;
    }
    table[line]++;

    for (auto const &x : table)
    {
        outfile << x.first // string (key)
                << ": "
                << x.second // string's value
                << std::endl;
    }

    return 0;
}