#include <vector>
#include <tuple>
#include <string>
#include <set>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <utility>

void createlist(std::vector<std::tuple<std::string, std::string>> edges, std::unordered_map<std::string, std::vector<std::string>> &list)
{

    for (int i = 0; i < edges.size(); i++)
    {
        // std::cout << std::get<0>(edges[i]) << " and " << std::get<1>(edges[i]) << std::endl;
        std::string a = std::get<0>(edges[i]);
        std::string b = std::get<1>(edges[i]);

        if (!list.count(a))
        {
            list[a] = {};
        }
        if (!list.count(b))
        {
            list[b] = {};
        }
        list[a].push_back(b);
        list[b].push_back(a);
    }
    return;
}

int shortestPath(std::vector<std::tuple<std::string, std::string>> edges, std::string nodeA, std::string nodeB)
{
    std::unordered_map<std::string, std::vector<std::string>> adjList;

    createlist(edges, adjList);

    std::set<std::string> visited;
    visited.insert(nodeA);

    std::queue<std::pair<std::string, int>> q;
    q.push({nodeA, 0});

    while (!q.empty())
    {
        std::pair<std::string, int> cur = q.front();
        q.pop();

        if (cur.first == nodeB)
        {
            return cur.second;
        }

        for (int i = 0; i < adjList[cur.first].size(); i++)
        {
            if (!visited.count(adjList[cur.first][i]))
            {
                q.push({adjList[cur.first][i], cur.second + 1});
                visited.insert(adjList[cur.first][i]);
            }
        }
    }

    // for(const auto &it: list) {
    //   std::cout << it.first << ": [";
    //   for(int i = 0; i < it.second.size(); i++) {
    //     std::cout << it.second[i] << " ";
    //   }
    //   std::cout << "]" << std::endl;
    // }

    return -1;
}

void main()
{
    std::vector<std::tuple<std::string, std::string>> edges0{
        {"w", "x"},
        {"x", "y"},
        {"z", "y"},
        {"z", "v"},
        {"w", "v"}};

    std::vector<std::tuple<std::string, std::string>> edges1{
        {"w", "x"},
        {"x", "y"},
        {"z", "y"},
        {"z", "v"},
        {"w", "v"}
    };

    std::vector<std::tuple<std::string, std::string>> edges2{
        {"a", "c"},
        {"a", "b"},
        {"c", "b"},
        {"c", "d"},
        {"b", "d"},
        {"e", "d"},
        {"g", "f"}
    };

    std::vector<std::tuple<std::string, std::string>> edges3{
        {"a", "c"},
        {"a", "b"},
        {"c", "b"},
        {"c", "d"},
        {"b", "d"},
        {"e", "d"},
        {"g", "f"}
    };

    std::vector<std::tuple<std::string, std::string>> edges4{
        {"a", "c"},
        {"a", "b"},
        {"c", "b"},
        {"c", "d"},
        {"b", "d"},
        {"e", "d"},
        {"g", "f"}
    };

    std::vector<std::tuple<std::string, std::string>> edges5{
        {"c", "n"},
        {"c", "e"},
        {"c", "s"},
        {"c", "w"},
        {"w", "e"}
    };

    shortestPath(edges0, "w", "z"); // -> 2
    shortestPath(edges1, "y", "x"); // -> 1
    shortestPath(edges2, "a", "e"); // -> 3
    shortestPath(edges3, "e", "c"); // -> 2
    shortestPath(edges4, "b", "g"); // -> -1
    shortestPath(edges5, "w", "e"); // -> 1
}