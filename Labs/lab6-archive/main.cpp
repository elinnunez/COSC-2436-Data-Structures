#include <iostream>
#include <string>
#include <fstream>
#include "ArgumentManager.h"
#include "avl.h"

using namespace std;

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);

    string infilename = am.get("input");
    string outfilename = am.get("output");

    ifstream infile(infilename);
    ofstream outfile(outfilename);

    // ifstream infile("input3.txt");
    // ofstream outfile("output3.txt");

    if (!infile.is_open())
    {
        cout << "File isn't open" << endl;
        return 1;
    }

    AVL<int> mytree;

    while (!infile.eof())
    {
        string line;
        getline(infile, line);

        while (getline(infile, line))
        {
            if(line.length() == 0) {
                continue;
            }

            mytree.insert(mytree.getRoot(), stoi(line));
        }
    }

    mytree.outputByLevel(mytree.getRoot(), outfile);

    return 0;
}