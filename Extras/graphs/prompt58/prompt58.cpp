#include <unordered_map>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool explore(std::unordered_map<int, std::vector<int>> graph, int current, set<int> &visited)
{
    if (visited.count(current))
    {
        return false;
    }
    cout << "insert current: " << current << endl;
    visited.insert(current);

    for (int i = 0; i < graph[current].size(); i++)
    {
        explore(graph, graph[current][i], visited);
    }

    return true;
}

int connectedComponentsCount(std::unordered_map<int, std::vector<int>> graph)
{
    set<int> visited;
    int count = 0;

    for (auto const &x : graph)
    {
        cout << "x.first: " << x.first << endl;
        if (explore(graph, x.first, visited) == true)
        {
            count++;
        }
    }
    return count;
}

// x.first = 0, explore(graph, 0, visited = {})
//-In explore-> visited = {0}, graph[0].size = 3
//   -In explore loop-> i = 0, graph[0][0] = 8, explore(graph, 8, visited = {0})
//                            -in explore(8)-> visited = {0,8}, graph[8].size = 2
//                              -In explore(8) loop-> i = 0, graph[8][0]=0, explore(graph, 0, visited={0,8})
//                                                        --In explore(0)-> visited has 0, return false back up
//                                                    i = 1, graph[8][1]=5, explore(graph, 5, visited={0,8})
//                                                        --In explore(5)-> visited = {0,8,5}, graph[5].size = 2
//                                                              -In explore(5) loop-> i = 0, graph[5][0]= 0, explore(graph, 0, visited={0,8,5}) false
//                                                                                    i = 1, graph[5][1]= 8, explore(graph, 8, visited={0,8,5}) false
//                                                              -End explore(5)-> return true back to i = 1 of explore(8) call
//                              -End explore(8) returns true back to i = 0 of explore(0) call;
//-
//                   i = 1, graph[0][1] = 1, explore(graph, 1, visited =  {0,8,5})
//                        -in explore(1)-> visited = {0,8,5,1}, graph[0].size = 1
//                          -in explore(1) loop-> i = 0, graph[1][0] = 0, explore(graph, 0, visited={0,8,5,1})
//                                                                         -in explore(0)-> returns false since visited has 0
//                        -end explore(1) return  true
//                   i = 2, graph[0][2] = 5, explore(graph, 5, visited =  {0,8,5,1})
//                       -in explore(5)-> return false since  5 is in  visited
//                       -end explore(5) return true
// end of explore(0) returns true;end
// count = 1
// x.first = 1, explore(graph, 1, visited = {0,8,5,1})
//-In explore(1) -> returns false since 1 in visited
// x.first = 5, explore(graph, 5, visited ={0,8,5,1})
//-In explore(5) -> returns false since 5 in visited
// x.first =  8, explore(graph, 8, visited = {0,8,5,1})
//-In explore(8) -> returns false, sincce 8 in visited
// x.first = 2,  explore(graph, 2, visited = {0,8,5,1})
//-In explore(2)-> visited = {0,8,5,1,2}, graph[2].size = 2;
//   -in explore(2) loop-> i = 0, graph[2][0] = 3, explore(graph, 3, visited = {0,8,5,1,2})
//                                                -in explore(3)-> visited = {0,8,5,1,2,3}, graph[3].size=2;
//                                                   -in explore(3) loop-> i = 0, graph[3][0]= 2, explore(graph, 2, visited={0,8,5,1,2,3})
//                                                                                               //explore(2) returns false since 2 in visited
//                                                                         i = 1, graph[3][1]= 4, explore(graph, 4, visited={0,8,5,1,2,3})
//                                                                                               //-in explore(4)-> visited= {0,8,5,1,2,3,4}, graph[4].size= 2;
//                                                                                                   -in explore(4) loop-> i = 0, graph[4][0]= 3, explore(graph, 3, visited={0,8,5,1,2,3,4})
//                                                                                                                                               -explore(3) -> returns false since 3 in visited
//                                                   -End explore(3) returns true back to i = 0 in explore(2) call
//                       i = 1, graph[2][1] = 4, explore(graph, 4, visited = {0,8,5,1,2,3,4})
//                                              -in explore(4)-> returns false since 4 in  visited
//  -End explore(2) returns true
// count = 2
// x.first = 3, explore(graph, 3, visited = {0,8,5,1,2,3,4}) ->
//-In explore(3)-> returns false since 3 in visited
//  same with 4

void main()
{
    std::unordered_map<int, std::vector<int>> graph0{
        {0, {8, 1, 5}},
        {1, {0}},
        {5, {0, 8}},
        {8, {0, 5}},
        {2, {3, 4}},
        {3, {2, 4}},
        {4, {3, 2}}
    };

    std::unordered_map<int, std::vector<int>> graph1{
        {1, {2}},
        {2, {1, 8}},
        {6, {7}},
        {9, {8}},
        {7, {6, 8}},
        {8, {9, 7, 2}}
    };

    std::unordered_map<int, std::vector<int>> graph2{
        {3, {}},
        {4, {6}},
        {6, {4, 5, 7, 8}},
        {8, {6}},
        {7, {6}},
        {5, {6}},
        {1, {2}},
        {2, {1}}
    };

    std::unordered_map<int, std::vector<int>> graph3;

    std::unordered_map<int, std::vector<int>> graph4{
        {0, {4, 7}},
        {1, {}},
        {2, {}},
        {3, {6}},
        {4, {0}},
        {6, {3}},
        {7, {0}},
        {8, {}},
    };

    connectedComponentsCount(graph0); // -> 2
    connectedComponentsCount(graph1); // -> 1
    connectedComponentsCount(graph2); // -> 3
    connectedComponentsCount(graph3); // -> 0
    connectedComponentsCount(graph4); // -> 5
}