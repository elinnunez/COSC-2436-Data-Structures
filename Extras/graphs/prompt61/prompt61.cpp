#include <vector>

void dfs(std::vector<std::vector<char>> &grid, int i, int j)
{
    if (i < 0 || i >= grid.size())
    {
        return;
    }
    if (j < 0 || j >= grid[i].size())
    {
        return;
    }
    if (grid[i][j] == 'W')
    {
        return;
    }
    
    grid[i][j] = 'W';

    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int islandCount(std::vector<std::vector<char>> grid)
{
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 'L')
            {
                dfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
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
        {'W', 'W'},
        {'W', 'W'}
    };

    islandCount(grid0); // -> 3
    islandCount(grid1); // -> 4
    islandCount(grid2); // -> 1
    islandCount(grid3); // -> 0
}