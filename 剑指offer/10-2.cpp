class Solution {
public:
    int numWays(int n) {
        vector<int> result(n+1, 1);
        for(int i = 2; i <= n; i++){
            result[i] = (result[i-1] + result[i-2])%1000000007;
        }
        return result[n];
    }
};
