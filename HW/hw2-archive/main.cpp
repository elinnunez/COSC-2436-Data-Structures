#include <iostream>
#include "ArgumentManager.h"
#include <fstream>
#include <string>
#include "list.h"

using namespace std;

int main(int argc, char *argv[])
{

    ArgumentManager am(argc, argv);

    string infilename = am.get("input");
    string outfilename = am.get("output");
    string comfilename = am.get("command");

    ifstream infile(infilename);
    ifstream comfile(comfilename);
    ofstream outfile(outfilename);

    // ifstream infile("input24.txt");
    // ifstream comfile("command24.txt");
    // ofstream outfile("myoutput24.txt");

    if (!infile.is_open())
    {
        cout << "File isn't open" << endl;
        return 1;
    }

    link list;
    int count = 1;

    string order;

    while (!infile.eof())
    {
        string line;

        getline(infile, order);
        cout << "Order = " << order << endl;

        while (getline(infile, line))
        {

            if (line == "")
            { //if line in textfile is empty, skip it
                continue;
            }

            bool isDupe = list.isDup(line);

            if (isDupe == true)
            {
                cout << "Duplicate: " << line << endl;
                continue;
            }
            else
            {
                if (order == "End")
                {
                    list.byEnd(line);
                    count += 1;
                }
                if (order == "Beginning" || order == "Length" || order == "Alphabetically")
                {
                    //Default appending before sorting
                    list.byBeginning(line);
                    count += 1;

                    if (order == "Length")
                    {
                        list.LengthSwap();
                    }

                    if (order == "Alphabetically")
                    {
                        list.byAlphabet();
                    }
                }
            }
        }
    }

    if (!comfile.is_open())
    {
        cout << "Command file isn't open" << endl;
        return 1;
    }
    else
    {

        string curCom;
        string curSort;

        string sus;
        int addIndex;

        string cline;

        while (getline(comfile, cline))
        {

            if (cline.length() == 0)
            {
                continue;
            }

            if (cline.substr(0, 4) == "Sort")
            {
                curSort = cline.at(6);
                if (curSort == "l")
                {
                    list.LengthSwap();
                }
                if (curSort == "a")
                {
                    list.byAlphabet();
                }
            }

            if (cline.substr(0, 3) == "Add")
            {
                sus = cline.substr(cline.find('(') + 1, cline.find(')') + -cline.find('(') - 1);
                addIndex = stoi(sus);

                curCom = cline.substr(cline.find('[') + 1, cline.find(']') + -cline.find('[') - 1);
                if (list.isDup(curCom) == true)
                {
                    continue;
                }
                else
                {

                    if (addIndex == 0)
                    {
                        list.byBeginning(curCom);
                        count += 1;
                    }
                    else
                    {
                        if (addIndex > count+1)
                        {
                            cout << "Count = " << count << " vs. AddIndex = " << addIndex << endl;
                            continue;
                        }
                        else
                        {
                            cout << "Adding: " << curCom << " : Index: " << addIndex << endl;
                            list.addAtLocation(addIndex, curCom, &count);
                            count += 1;
                        }
                    }
                }
            }

            if (cline.substr(0, 6) == "Remove")
            {
                sus = cline.substr(cline.find('[') + 1, cline.find(']') + -cline.find('[') - 1);
                cout << "Remove: " << sus << endl;

                list.removeAtStr(sus, &count);
            }

        }

        // list.printList();

        list.outfile(&outfile);

        return 0;
    }
}
