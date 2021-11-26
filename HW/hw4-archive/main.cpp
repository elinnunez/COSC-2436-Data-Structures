#include <iostream>
#include <string>
#include <fstream>
#include "ArgumentManager.h"
#include "pqueue.h"
#include "queue.h" 

using namespace std;

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);

    string infilename = am.get("input");
    string outfilename = am.get("output");

    ifstream infile(infilename);
    ofstream outfile(outfilename);

    // ifstream infile("input43.txt");
    // ofstream outfile("testoutput43.txt");

    if (!infile.is_open())
    {
        cout << "File isn't open" << endl;
        return 1;
    }

    PQueue pq;
    Queue q;

    while (!infile.eof())
    {
        string line;

        while (getline(infile, line))
        {
            if(line.length() == 0) {
                continue;
            }

            string exp = line.substr(0, line.find("("));
            int priority = stoi(line.substr(line.find("(")+1, line.length() - line.find(")")));
            
            pq.enqueue(exp, priority);
        }
    }

    while(!pq.isEmpty()) {
        string cur = pq.getFront();

        string com = cur.substr(0, cur.find(":"));

        if(com == "PRINT") {
            // cout << "PRINT CALLED: " << endl;
            if(!q.isEmpty()) {
                outfile << q.getFront() << endl;
                // cout << q.getFront() << endl;
                q.dequeue();
            }
        } else {
            string exp = cur.substr(cur.find("[")+1, cur.find(']') - cur.find('[') - 1);
            
            if(q.isEmpty() && com != "DECODE") {
                // continue;
            } else {
                if(com == "DECODE") {
                    q.enqueue(exp);
                    // cout << "DECODE CALLED: " << exp << endl;
                } else if (com == "REMOVE") {
                    q.removeChar(exp[0]);
                    string topush = q.getFront();
                    q.enqueue(topush);
                    q.dequeue();
                    // cout << "After REMOVE [" << exp[0] << "]: " << topush << endl;
                } else {
                    char a = exp[0];
                    char b = exp[2];
                    string temp;
                    if(com == "REPLACE") {
                        q.replaceChar(a, b);
                        temp = q.getFront();
                        q.enqueue(temp);
                        q.dequeue();
                        // cout << "After REPLACE [" << exp << "]: " << temp << endl;
                    } else if (com == "SWAP") {
                        q.swapChar(a, b);
                        temp = q.getFront();
                        q.enqueue(temp);
                        q.dequeue();
                        // cout << "After SWAP [" << exp << "]: " << temp << endl;
                    } else {
                        q.addChar(a, b);
                        temp = q.getFront();
                        q.enqueue(temp);
                        q.dequeue();
                        // cout << "After ADD [" << exp << "]: " << temp << endl;
                    }
                }
            }
        }
        pq.dequeue();
    }

    return 0;
}