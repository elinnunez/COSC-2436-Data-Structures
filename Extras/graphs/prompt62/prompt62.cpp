#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>

int dfs(std::vector<std::vector<char>> &grid, int i, int j)
{
    if (i < 0 || i >= grid.size())
    {
        return 0;
    }
    if (j < 0 || j >= grid[i].size())
    {
        return 0;
    }
    if (grid[i][j] == 'W')
    {
        return 0;
    }
    
    grid[i][j] = 'W';

    int u = dfs(grid, i - 1, j);
    int d = dfs(grid, i + 1, j);
    int l = dfs(grid, i, j - 1);
    int r = dfs(grid, i, j + 1);

    return 1 + u + d + l + r;
}

int minimumIsland(std::vector<std::vector<char>> grid)
{
    int minLand = grid.size() * grid[0].size();
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 'L')
            {
                minLand = std::min(dfs(grid, i, j), minLand);
            }
        }
    }
    return minLand;
}

void main()
{
    std::vector<std::vector<char>> grid0{
        {'W', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'L', 'W'},
        {'W', 'W', 'L', 'L', 'W'},
        {'L', 'W', 'W', 'L', 'L'},
        {'L', 'L', 'W', 'W', 'W'}
    };

    std::vector<std::vector<char>> grid1{
        {'L', 'W', 'W', 'L', 'W'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'L', 'W', 'L', 'W'},
        {'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'L', 'L', 'L'}
    };

    std::vector<std::vector<char>> grid2{
        {'L', 'L', 'L'},
        {'L', 'L', 'L'},
        {'L', 'L', 'L'}
    };

    std::vector<std::vector<char>> grid3{
        {'W', 'W'},
        {'L', 'L'},
        {'W', 'W'},
        {'W', 'L'}
    };

    minimumIsland(grid0); // -> 2
    minimumIsland(grid1); // -> 1
    minimumIsland(grid2); // -> 9
    minimumIsland(grid3); // -> 1
}