#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "ArgumentManager.h"

using namespace std;

void swap(string &str, int x, int y) {
    char temp = str[x];
    str[x] = str[y];
    str[y] = temp;
}

void permuteStr(string &str, int size, set<string> &perms, int startIndex = 0) {
    //base case;
    if(startIndex == size-1) {
        perms.insert(str);
        return;
    }

    for(int i = startIndex; i < size; i++) {
        swap(str, startIndex, i);
        permuteStr(str, size, perms, startIndex + 1);
        cout << str << endl;
        perms.insert(str);
        swap(str, startIndex, i);            
    }
}

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);

    string infilename = am.get("input");
    string outfilename = am.get("output");

    ifstream infile(infilename);
    ofstream outfile(outfilename);

    string line;

    set<string> perms;

    if(!infile.is_open()) {
        cout << "File Not Open" << endl;
        return -1;
    }

    while(!infile.eof()) {
        infile >> line;

        if(line.length() == 0) {
            outfile << "no permutation";
        }

        permuteStr(line, line.size(), perms);
        
    }

    set<string>:: iterator it;
    for(it = perms.begin(); it != perms.end(); it++) {
        outfile << *it << endl;
    }



    infile.close();
    outfile.close();
    
    return 0;
}