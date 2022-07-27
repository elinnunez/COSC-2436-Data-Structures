#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

// dfs recursive
bool hasPathRec(std::unordered_map<std::string, std::vector<std::string>>& graph, std::string src, std::string dst) {
  if(src == dst) {
    return true;
  }

  for(int i = 0; i < graph[src].size(); i++) {
    if(hasPathRec(graph, graph[src][i], dst) == true) {
      return true;
    }
  }
  return false;
}

// bfs
bool hasPath(std::unordered_map<std::string, std::vector<std::string>>& graph, std::string src, std::string dst)
{
    if (src == dst)
    {
        return true;
    }

    std::queue<std::string> q;
    q.push(src);

    while (!q.empty())
    {
        std::string cur = q.front();
        q.pop();
        if (cur == dst)
        {
            return true;
        }
        for (int i = 0; i < graph[cur].size(); i++)
        {
            q.push(graph[cur][i]);
        }
    }

    return false;
}

int main()
{
    std::unordered_map<std::string, std::vector<std::string>> graph0{
        {"f", {"g", "i"}},
        {"g", {"h"}},
        {"h", {}},
        {"i", {"g", "k"}},
        {"j", {"i"}},
        {"k", {}}
    };

    std::unordered_map<std::string, std::vector<std::string>> graph1{
        {"f", {"g", "i"}},
        {"g", {"h"}},
        {"h", {}},
        {"i", {"g", "k"}},
        {"j", {"i"}},
        {"k", {}}
    };

    std::unordered_map<std::string, std::vector<std::string>> graph2{
        {"f", {"g", "i"}},
        {"g", {"h"}},
        {"h", {}},
        {"i", {"g", "k"}},
        {"j", {"i"}},
        {"k", {}}
    };

    std::unordered_map<std::string, std::vector<std::string>> graph3{
        {"v", {"x", "w"}},
        {"w", {}},
        {"x", {}},
        {"y", {"z"}},
        {"z", {}}
    };

    hasPath(graph0, "f", "k"); // 1 (true)
    hasPath(graph1, "f", "j"); // 0 (false)
    hasPathRec(graph2, "i", "h"); // 1 (true)
    hasPathRec(graph3, "v", "w"); // 1 (true)

    return 1;
}