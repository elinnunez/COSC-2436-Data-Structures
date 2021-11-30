#include <iostream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
#include "bst.h"

using namespace std;

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);

    string infilename = am.get("input");
    string outfilename = am.get("output");

    ifstream infile(infilename);
    ofstream outfile(outfilename);

    // ifstream infile("input31.txt");
    // ofstream outfile("output31.txt");

    if(!infile.is_open()) {
        cout << "File isn't open" << endl;
        return 1;
    }

    BST tree;

    string line;
    string delimiter = " ";
    int temp;

    getline(infile, line);

    int pos = 0;

    while((pos = line.find(delimiter)) != string::npos) {
        temp = stoi(line.substr(0, pos));
        tree.insert(tree.getRoot(), temp);
        line.erase(0, pos + delimiter.length());
    }
    tree.insert(tree.getRoot(), stoi(line));

    string ran = "x";

    tree.printPreOrder(tree.getRoot(), ran, outfile);

    return 0;
}