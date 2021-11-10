#include <iostream>
#include "ArgumentManager.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include "list.h"

using namespace std;

int main(int argc, char *argv[])
{

    ArgumentManager am(argc, argv);

    string infilename = am.get("input");
    string outfilename = am.get("output");

    ifstream infile(infilename);
    ofstream outfile(outfilename);

    // ifstream infile("input3.txt");
    // ofstream outfile("myoutput3.txt");

    if (!infile.is_open())
    {
        cout << "File isn't open" << endl;
        return 1;
    }

    linked list;
    string name;
    int score;

    while (!infile.eof())
    {
        string line;

        while (getline(infile, line))
        {
            line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());

            try
            {
                //fixed case if a comma isn't found in string
                if (line.find(',') != string::npos)
                {
                    name = line.substr(0, line.find(','));
                    score = stoi(line.substr(line.find(',') + 1));
                } else {
                    continue;
                }

            }
            catch (const invalid_argument &ia)
            {
                cerr << "Invalid argument: " << ia.what() << '\n';
                continue;
            }

            list.addNode(name, score);
        }
    }

    list.sortList();
    list.sendOutput(outfile);

    // list.printList();

    return 0;
}