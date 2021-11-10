#include <iostream>
#include "ArgumentManager.h"
#include <fstream>
#include <sstream>
#include "queue.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);

    string infilename = am.get("input");
    string outfilename = am.get("output");

    ifstream infile(infilename);
    ofstream outfile(outfilename);

    // ifstream infile("mytest.txt");
    // ofstream outfile("myoutput.txt");

    if (!infile.is_open())
    {
        cout << "File isn't open" << endl;
        return 1;
    }

    Queue q1, q2, q3, shelf;

    string t1, t2;
    string delimiter = ",";
    string temp;

    getline(infile, t1);
    getline(infile, t2);

    // Add to Queue 1
    int pos = 0;
    while((pos = t1.find(delimiter)) != string::npos) {
        temp = t1.substr(0, pos);
        q1.enqueue(temp);
        t1.erase(0, pos + delimiter.length());
    }
    q1.enqueue(t1);

    // Add to Queue 2
    pos = 0;
    while((pos = t2.find(delimiter)) != string::npos) {
        temp = t2.substr(0, pos);
        q2.enqueue(temp);
        t2.erase(0, pos + delimiter.length());
    }
    q2.enqueue(t2);


    int totalTime = 0;

    while(!q1.isEmpty() || !q2.isEmpty()) {
        if(q1.isEmpty()) {
            // continue;
        }else if(q1.getFront().substr(0,7) != "compsci") {
            q3.enqueue(q1.getFront());
            q1.dequeue();
            totalTime += 10;
        } else {
            shelf.enqueue(q1.getFront());
            q1.dequeue();
            totalTime+=20;
        }
        if(q2.isEmpty()) {
            // continue;
        }else if(q2.getFront().substr(0,7) != "compsci") {
            q3.enqueue(q2.getFront());
            q2.dequeue();
            totalTime += 10;
        } else {
            shelf.enqueue(q2.getFront());
            q2.dequeue();
            totalTime +=20;
        }
    }

    // Add discarded books to shelf
    while(!q3.isEmpty()) {
        shelf.enqueue(q3.getFront());
        q3.dequeue();
        totalTime += 20;
    }


    outfile << totalTime << '\n';
    shelf.sendOutput(outfile);

    cout << totalTime << endl;
    shelf.display();
    
    return 0;
}