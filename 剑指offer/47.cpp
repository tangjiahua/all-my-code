class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size() - 1;
        int col = grid[0].size() - 1;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for(int i = 0; i <= row; i++){
            for(int j = 0; j <= col; j++){
                if(i == 0 && j == 0) continue;
                if(i == 0){
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                    continue;
                }
                if(j == 0){
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                    continue;
                }
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[row][col];
    }
};
