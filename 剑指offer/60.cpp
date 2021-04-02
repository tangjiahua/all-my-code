class Solution {
public:
    vector<double> twoSum(int n) {
         int dp[15][70];
         memset(dp, 0, sizeof(dp));
         for(int i = 1; i <= 6; i++){
             dp[1][i] = 1;
         }
         for(int i = 2; i <= n; i++){
             for(int j = i; j <= i*6; j++){
                 for(int k = 1; k <= 6; k++){
                     if(j-k <= 0) break;
                     dp[i][j] += dp[i-1][j-k];
                 }
             }
         }
         vector<double> result;
         int all = pow(6, n);
         for(int i = n; i <= n*6; i++){
             result.push_back(dp[n][i]*1.0/all);
         }
         return result;
    }
};
