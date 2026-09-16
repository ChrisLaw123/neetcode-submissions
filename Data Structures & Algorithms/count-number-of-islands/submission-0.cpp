class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int res{};
        for (int i{}; i < grid.size(); i++) {
            for (int j{}; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        // this is just going to be setting the 0s
        if (grid[x][y] == '0') {
            return;
        }
        grid[x][y] = '0';
        if (x - 1 >= 0)             dfs(grid, x - 1, y);
        if (x + 1 < grid.size())    dfs(grid, x + 1, y);
        if (y - 1 >= 0)             dfs(grid, x, y - 1);
        if (y + 1 < grid[0].size()) dfs(grid, x, y + 1);

        return;
    }
};
