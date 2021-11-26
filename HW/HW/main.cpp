#include <iostream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
#include "btree.h"

using namespace std;

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);

    const string input = am.get("input");
    const string command = am.get("command");
    const string output = am.get("output");

    ifstream infile(input);
    ifstream comfile(command);
    ofstream outfile(output);

    // ifstream infile("input52.txt");
    // ifstream comfile("command52.txt");
    // ofstream outfile("output52.txt");

    int val;
    string line;

    getline(comfile, line);

    int deg = stoi(line.substr(7));

    btree *bTree = new btree(deg);

    while (!infile.eof())
    {
        infile >> val;
        bTree->insert(val);
    }

    outfile << "Height=" << bTree->getHeight() << endl;

    while (getline(comfile, line))
    {
        if (line[0] == 'L')
        {
            int digit = stoi(line.substr(6));

            if (digit > bTree->getHeight()) {
                outfile << "empty";
            }

            bTree->printLevel(outfile, digit);
        }
    }
}