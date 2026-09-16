class Solution {
   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int max{};
        vector<vector<int>> memoization (matrix.size(),vector<int>(matrix[0].size(), 0));
        for (int i{}; i < matrix.size(); i++) {
            for (int j{}; j < matrix[0].size(); j++) {
                memoization[i][j] = dfs(matrix, i, j, memoization);
                if (max < memoization[i][j]) {
                    max = memoization[i][j];
                }
            }
        }
        return max;
    }

    int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>&memoization) {
        // if within bounds and greater than the current pos
        if (memoization[x][y] != 0) return memoization[x][y];

        int longest{1};
        if (x + 1 < matrix.size() && matrix[x + 1][y] > matrix[x][y])
            longest = max(longest, dfs(matrix, x + 1, y, memoization) + 1);
        if (x - 1 >= 0 && matrix[x - 1][y] > matrix[x][y])
            longest = max(longest, dfs(matrix, x - 1, y, memoization) + 1);
        if (y + 1 < matrix[0].size() && matrix[x][y + 1] > matrix[x][y])
            longest = max(longest, dfs(matrix, x, y + 1, memoization) + 1);
        if (y - 1 >= 0 && matrix[x][y - 1] > matrix[x][y])
            longest = max(longest, dfs(matrix, x, y - 1, memoization) + 1);
        memoization[x][y] = longest;
        return longest;
    }
};
