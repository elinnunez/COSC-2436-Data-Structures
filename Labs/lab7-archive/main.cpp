#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "ArgumentManager.h"

using namespace std;

const static int INF = 999;

int selectMinVertex(vector<int>& val, vector<bool>& rel, int size) {
    int min = INF;
    int vertex;
    for(int i = 1; i < size+1; i++) {
        if(rel[i] == false && val[i] < min) {
            vertex = i;
            min = val[i];
        }
    }

    // cout << "vertex: " << vertex << endl;

    return vertex;
}

int getShortestPath(int **arr, int size, int start, int end){
    int *parent = new int[size+1];
    vector<bool> visited(size+1, false);
    vector<int> distance(size+1, INF);

    parent[start] = -1;
    distance[start] = 0;

    for(int i = 1; i < size; i++) {
        int mv = selectMinVertex(distance, visited, size);
        visited[mv] = true;

        for(int j = 1; j < size+1; j++) {
            if(arr[mv][j] != 0 && visited[j] == false && distance[mv] != INF && (distance[mv] + arr[mv][j] < distance[j])) {
                distance[j] = distance[mv] + arr[mv][j];
                parent[j] = mv;
            }
        }
    }

    return distance[end];

};

void insertEdges(int **arr, int src, int dest, int w) {
    arr[src][dest] = w;
    arr[dest][src] = w;
}

void printGraph(int ** arr, int size) {
    cout <<"   0 1 2 3 4 5 6 7" << endl;
    cout <<"   - - - - - - - -" << endl;
    for(int i = 0; i < size+1; i++) {
        cout << i << ": "; 
        for(int j = 0; j < size+1; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}

// void insertStatic(int **arr) {
//     arr[1][2] = 5;
//     arr[2][1] = 5;
//     arr[1][3] = 3;
//     arr[3][1] = 3;
//     arr[1][4] = 6;
//     arr[4][1] = 6;
//     arr[2][5] = 2;
//     arr[5][2] = 2;
//     arr[4][5] = 3;
//     arr[5][4] = 3;
//     arr[5][6] = 4;
//     arr[6][5] = 4;
//     arr[5][7] = 5;
//     arr[7][5] = 5;
// }

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

    string line;
    int size, start, end;
    
    getline(infile, line);

    string si(1, line[0]);
    string st(1, line[4]);
    string en(1, line[6]);

    size = stoi(si);
    start = stoi(st);
    end = stoi(en);

    int **adjL = new int*[size+1];

    for(int i = 0; i < size+1; i++) {
        adjL[i] = new int[size+1];
        // cout << i << ": "; 
        for(int j = 0; j < size+1; j++) {
            adjL[i][j] = 0;
            // cout << adjL[i][j] << " ";
        }
        cout << endl;
    }

    while(!infile.eof()) {
        getline(infile, line);

        if(line == "") {
            continue;
        }

        int src, dest, weight;

        string srce(1, line[0]);
        string des(1, line[2]);
        string wt(1, line[4]);

        src = stoi(srce);
        // cout << src << endl;
        dest = stoi(des);
        // cout << dest << endl;
        weight = stoi(wt);
        // cout << weight << endl;

        insertEdges(adjL, src, dest, weight);
    }

    outfile << getShortestPath(adjL, size, start, end);
    // printGraph(adjL, size);

    return 0;
}