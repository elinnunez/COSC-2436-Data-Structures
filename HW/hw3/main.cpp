#include <iostream>
#include <fstream>
#include <algorithm>
#include "ArgumentManager.h"
#include "functions.h"
#include "dll.h"
#include "stack.h"

using namespace std;

void flipReserve(Stack *og)
{
    Stack temp;

    while (!og->isEmpty())
    {
        Node *cur = og->peek();
        string t = cur->type;
        string e = cur->equation;
        temp.push(t, e);
        og->pop();
    }

    *og = temp;
}

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);

    string infilename = am.get("input");
    string outfilename = am.get("output");
    string comfilename = am.get("command");

    ifstream infile(infilename);
    ifstream comfile(comfilename);
    ofstream outfile(outfilename);

    // ifstream infile("input37.txt");
    // ifstream comfile("command37.txt");
    // ofstream outfile("outtest37.txt");

    if (!infile.is_open())
    {
        cout << "File isn't open" << endl;
        return 1;
    }

    DoublyLL list;
    Stack reserve;

    while (!infile.eof())
    {
        string line;
        string type;
        string equation;

        getline(infile, line);

        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());

        if (line == "")
        {
            continue;
        }
        else
        {
            if (line.find(':') != string::npos)
            {
                type = line.substr(0, line.find(':'));
                equation = line.substr(line.find(':') + 1);
                list.addEnd(type, equation);
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
        string cline;

        while (getline(comfile, cline))
        {
            if (cline == "")
            {
                continue;
            }
            else if (cline.find('(') != string::npos == true)
            {
                string com = cline.substr(cline.find('(') + 1, cline.find(')') - cline.find('(') - 1);

                if (cline.substr(0, 10) == "removeList")
                {
                    list.removeComList(com);
                }
                else if (cline.substr(0, 10) == "popReserve")
                {
                    Node *top = reserve.peek();
                    string t = top->type;
                    string e = top->equation;
                    list.addAtPos(com, t, e);
                    reserve.pop();
                }
                else if (cline.substr(0, 11) == "convertList")
                {
                    list.convertComList(com);
                }
                else if (cline.substr(0, 11) == "pushReserve")
                {
                    if(list.isEmpty()) {
                        continue;
                    } else {
                        reserve.pushComReserve(list.returnHead(), com, list.getSize());
                        list.removeComList(com);
                    }
                }
                else if (cline.substr(0, 12) == "emptyReserve")
                {
                    while (!reserve.isEmpty())
                    {
                        Node *cur = reserve.peek();
                        // cout << "Cur RT: " << cur->type << " | " << cur->equation << endl;
                        string t = cur->type;
                        string e = cur->equation;
                        list.addAtPos(com, t, e);
                        reserve.pop();
                    }
                }
            }
            else
            {
                if (cline == "printList")
                {
                    //output list to file
                    list.printList(&outfile);
                }
                else if (cline == "printListBackwards")
                {
                    list.printRevList(&outfile);
                }
                else if (cline == "flipReserve")
                {
                    //reverse the reserve stack
                    flipReserve(&reserve);
                }
                else if (cline == "printReserveSize")
                {
                    //print reserve size to file;
                    outfile << "Reserve Size: " << reserve.getSize() << endl;
                    outfile << endl;
                }
                else if (cline == "convertReserve")
                {
                    //change top of reserve stack to other type
                    reserve.convertReserve();
                }
                else if (cline == "printReserveTop")
                {
                    //print reserve top to file
                    //Top of Reserve: type:equation
                    reserve.printReserveTop(&outfile);
                }
            }
        }
    }

    return 0;
}