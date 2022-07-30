#include <unordered_map>
#include <vector>
#include <set>
#include <iostream>
#include <cmath>

bool explore(std::unordered_map<int, std::vector<int>> graph, int current, std::set<int> &visited, int &count)
{
    if (visited.count(current))
    {
        return false;
    }
    visited.insert(current);
    count++;

    for (int i = 0; i < graph[current].size(); i++)
    {
        explore(graph, graph[current][i], visited, count);
    }
    return true;
}

int largestComponent(std::unordered_map<int, std::vector<int>> graph)
{
    int maxcount = 0;
    std::set<int> visited;
    int count = 0;

    for (const auto &it : graph)
    {
        if (explore(graph, it.first, visited, count) == true)
        {
            std::cout << "current count: " << count << " vs max count: " << maxcount << std::endl;
            maxcount = std::max(maxcount, count);
            count = 0;
            std::cout << "Max Count: " << maxcount << std::endl;
        }
    }

    return maxcount;
}

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
        {8, {}}
    };

    largestComponent(graph0); // -> 4
    largestComponent(graph1); // -> 6
    largestComponent(graph2); // -> 5
    largestComponent(graph3); // -> 0
    largestComponent(graph4); // -> 3
}