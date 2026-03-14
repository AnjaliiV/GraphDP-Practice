class Solution {
public:
    int m, n;

    int helper(int i, int j, vector<vector<int>> &dungeon, vector<vector<int>> &dp) {
        // Base Case: out of bounds
        if (i >= m || j >= n) return 1e9;

        // If already computed
        if (dp[i][j] != -1) return dp[i][j];

        // Destination cell
        if (i == m - 1 && j == n - 1) {
            return max(1, 1 - dungeon[i][j]);
        }

        int right = helper(i, j + 1, dungeon, dp);
        int down = helper(i + 1, j, dungeon, dp);

        int result = min(right, down) - dungeon[i][j];

        return dp[i][j] = (result > 0) ? result : 1;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0, dungeon, dp);
    }
};
