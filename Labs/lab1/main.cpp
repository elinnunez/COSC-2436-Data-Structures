#include <iostream>
#include <string>
#include "ArgumentManager.h"
#include <fstream>
#include <set>

using namespace std;

void getPermutation(set<string> &perms, string unfixed, string fixed = "")
{
    if (unfixed.length() == 0)
    {
        
        cout << fixed << endl;
        perms.insert(fixed);
    }
    else
    {
        for (int i = 0; i < unfixed.length(); i++)
        {
            string f = fixed + unfixed.at(i);

            string uf = unfixed.substr(0, i) + unfixed.substr(i + 1);
            getPermutation(perms, uf, f);
        }
    }
}
int main(int argc, char **argv)
{

    ArgumentManager am(argc, argv);

    string infilename = am.get("input");
    string outfilename = am.get("output");

    ifstream infile(infilename);
    ofstream outfile(outfilename);

    string line;

    set<string> perms;

    if (!infile.is_open())
    {
        cout << "File Not Open" << endl;
        return -1;
    }

    while (!infile.eof())
    {
        infile >> line;

        if (line.length() == 0)
        {
            outfile << "no permutation";
        }

        getPermutation(perms, line);
    }

    set<string>::iterator it;
    for (it = perms.begin(); it != perms.end(); it++)
    {
        outfile << *it << endl;
    }

    return 0;
}