#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
#include <set>
#include <stack>
#include <iostream>

bool undirectedPathIter(std::vector<std::tuple<std::string, std::string>> edges, std::string source, std::string dst)
{
    std::unordered_map<std::string, std::vector<std::string>> hset;

    for (int i = 0; i < edges.size(); i++)
    {
        hset[std::get<0>(edges[i])].push_back(std::get<1>(edges[i]));
        hset[std::get<1>(edges[i])].push_back(std::get<0>(edges[i]));
    }

    std::set<std::string> visited;

    std::stack<std::string> stk;
    stk.push(source);
    visited.insert(source);

    while (!stk.empty())
    {
        std::string curr = stk.top();
        stk.pop();

        for (int i = 0; i < hset[curr].size(); i++)
        {
            if (hset[curr][i] == dst)
            {
                return true;
            }
            if (!visited.count(hset[curr][i]))
            {
                visited.insert(hset[curr][i]);
                stk.push(hset[curr][i]);
            }
        }
    }

    return false;
}

bool hasPath(std::unordered_map<std::string, std::vector<std::string>> &adj, std::string src, std::string dst, std::set<std::string> &visited)
{
    if (src == dst)
    {
        return true;
    }

    if (visited.count(src))
    {
        return false;
    }

    visited.insert(src);

    for (int i = 0; i < adj[src].size(); i++)
    {
        if (hasPath(adj, adj[src][i], dst, visited) == true)
        {
            return true;
        }
    }

    return false;
}

bool undirectedPath(std::vector<std::tuple<std::string, std::string>> edges, std::string source, std::string dst)
{
    std::unordered_map<std::string, std::vector<std::string>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        adj[std::get<0>(edges[i])].push_back(std::get<1>(edges[i]));
        adj[std::get<1>(edges[i])].push_back(std::get<0>(edges[i]));
    }

    // for(const auto& it: adj) {
    //   std::cout << it.first << ": {";
    //   for(int i = 0; i < adj[it.first].size(); i++) {
    //     if(i == adj[it.first].size()-1) {
    //       std::cout << adj[it.first][i] << "}\n";
    //     } else {
    //      std::cout << adj[it.first][i] << ", ";
    //     }
    //   }
    // }

    std::set<std::string> visited;

    return hasPath(adj, source, dst, visited);
}

int main()
{
    std::vector<std::tuple<std::string, std::string>> edges0{
        {"i", "j"},
        {"k", "i"},
        {"m", "k"},
        {"k", "l"},
        {"o", "n"}
    };

    std::vector<std::tuple<std::string, std::string>> edges1{
        {"i", "j"},
        {"k", "i"},
        {"m", "k"},
        {"k", "l"},
        {"o", "n"}
    };

    std::vector<std::tuple<std::string, std::string>> edges2{
        {"i", "j"},
        {"k", "i"},
        {"m", "k"},
        {"k", "l"},
        {"o", "n"}
    };

    std::vector<std::tuple<std::string, std::string>> edges3{
        {"i", "j"},
        {"k", "i"},
        {"m", "k"},
        {"k", "l"},
        {"o", "n"}
    };

    undirectedPath(edges0, "j", "m"); // -> 1 (true)
    undirectedPath(edges1, "m", "j"); // -> 1 (true)
    undirectedPathIter(edges2, "l", "j");  // -> 1 (true)
    undirectedPathIter(edges3, "k", "o");  // -> 0 (false)

    return 1;
}