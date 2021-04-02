class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // [7, 1, 1, 1, 1, 1];
        int max = -1;
        bool flag = false;
        if(prices.size() == 0 || prices.size() == 1) return 0;
        for(int i = 1; i < prices.size(); i++){
            int min;
            if(prices[i] < prices[i-1]){
                min = prices[i];
            } else{
                min = prices[i-1];
            }

            if(prices[i] - prices[i-1] > max){
                max = prices[i] - prices[i-1];
                flag = true;
            } 
            prices[i] = min;
        }
        return flag ? max : 0;
    }
};
