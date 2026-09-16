class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max{};
        for (int i{}; i < grid.size(); i++) {
            for (int j{}; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int curr{};
                    dfs(grid, i, j, curr);
                    if (curr > max) max = curr;
                }
            }
        }

        return max;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int& curr) {
        // this is just going to be setting the 0s
        if (grid[x][y] == 0) {
            return;
        }
        grid[x][y] = 0;
        curr++;
        if (x - 1 >= 0)             dfs(grid, x - 1, y, curr);
        if (x + 1 < grid.size())    dfs(grid, x + 1, y, curr);
        if (y - 1 >= 0)             dfs(grid, x, y - 1, curr);
        if (y + 1 < grid[0].size()) dfs(grid, x, y + 1, curr);

        return;
    }
};
