#include <iostream>
#include "ArgumentManager.h"
#include <fstream>
#include <string>
#include <queue>
#include "pq.h"

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

    PQueue pq;

    while (!infile.eof())
    {
        string line;

        while (getline(infile, line))
        {
            if(line.length() == 0) {
                continue;
            }

            double num = stod(line.substr(line.find_last_of(" ")));
            string exp = line.substr(0, line.find_last_of(" "));

            pq.enqueue(exp, num);
        }
    }

    pq.sendOutput(outfile);

    return 0;
}