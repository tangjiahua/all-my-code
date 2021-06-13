class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> res = vector<vector<int>>(prices.size(), vector<int>(2, 0));
        // res[0][1] = - prices[0];

        // // 0 持有现金
        // // 1 持有股票
        // for(int i = 1; i < prices.size(); i++){
        //     res[i][0] = max(res[i-1][0], res[i-1][1] + prices[i]);
        //     res[i][1] = max(res[i-1][1], res[i-1][0] - prices[i]);
        // }

        // return res[prices.size() - 1][0];
        if(prices.size() <= 1) return 0;
        int res = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i+1] - prices[i] > 0){
                res += prices[i+1] - prices[i];
            } 
        }
        return res;
    }
};
