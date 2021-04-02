class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() <= 1) return 0;

        int lowDay = prices[0], maxProfit = -INT_MAX;
        for(auto price : prices){
            if(price < lowDay){
                lowDay = price;
                continue;
            }
            if(price - lowDay > maxProfit){
                maxProfit = price - lowDay;

            }

        }
        return maxProfit > 0 ? maxProfit : 0;
    }
};
