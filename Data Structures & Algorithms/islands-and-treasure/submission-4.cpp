class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = 2147483647;
        queue<std::pair<int, int>> q;
        //multi source bfs from each treasure chest

        for (int i{}; i < grid.size(); i++) {
            for (int j{}; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int currDistance{1};
        while (!q.empty()) {

            for (int i = q.size() - 1; i >= 0; i--) {
                std::pair<int, int> curr = q.front();
                q.pop();
                if (curr.first - 1 >= 0 && grid[curr.first - 1][curr.second] == INF) {
                    grid[curr.first - 1][curr.second] = currDistance;
                    q.push({curr.first - 1, curr.second});
                }
                if (curr.first + 1 < grid.size() && grid[curr.first + 1][curr.second] == INF) {
                    grid[curr.first + 1][curr.second] = currDistance;
                    q.push({curr.first + 1, curr.second});
                }
                if (curr.second - 1 >= 0 && grid[curr.first][curr.second - 1] == INF) {
                    grid[curr.first][curr.second - 1] = currDistance;
                    q.push({curr.first, curr.second - 1});
                }
                if (curr.second + 1 < grid[0].size() && grid[curr.first][curr.second + 1] == INF) {
                    grid[curr.first][curr.second + 1] = currDistance;
                    q.push({curr.first, curr.second + 1});
                }
            }
            currDistance++;
        }
    }
};
