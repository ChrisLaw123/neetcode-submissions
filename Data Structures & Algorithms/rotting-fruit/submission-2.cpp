class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //multi point bfs
        int goodCount{};
        queue<std::pair<int, int>> q;
        //first count the number of good bananas and save the points of the rotting bananas
        for (int i{}; i < grid.size(); i++) {
            for (int j{}; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) goodCount++;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }

        //create a counter and start iterating bfs on each rotten fruit
        int time{};
        if (goodCount == 0) return 0;
        
        while (!q.empty()) {
            int prevCount = goodCount;
            time++;
            for (int i = q.size() - 1; i >= 0; i--) {
                std::pair<int, int> point = q.front();
                q.pop();
                if ((point.first - 1) >= 0 && grid[point.first - 1][point.second] == 1) {
                    grid[point.first - 1][point.second] = 2;
                    q.push({point.first - 1, point.second});
                    goodCount -= 1;
                }
                if ((point.first + 1) < grid.size() && grid[point.first + 1][point.second] == 1) {
                    grid[point.first + 1][point.second] = 2;
                    q.push({point.first + 1, point.second});
                    goodCount -= 1;
                }
                if ((point.second - 1) >= 0 && grid[point.first][point.second - 1] == 1) {
                    grid[point.first][point.second - 1] = 2;
                    q.push({point.first, point.second - 1});
                    goodCount -= 1;
                }
                if ((point.second + 1) < grid[0].size() && grid[point.first][point.second + 1] == 1) {
                    grid[point.first][point.second + 1] = 2;
                    q.push({point.first, point.second + 1});
                    goodCount -= 1;
                }
                if (goodCount == 0) return time;
                if (prevCount == goodCount) return - 1;
            }
        }
        //if the number of good fruit doesnt decrease after a cycle and is non zero, then return -1, else return # of cycles
        return -1;
    }
};
