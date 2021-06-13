class Solution {
public:
    int i = 1, j = 1, total = 0;
    vector<vector<int>> result;
    vector<vector<int>> findContinuousSequence(int target) {
        while(i <= target/2){
            if(total < target){
                total += j;
                j++;
            }else if(total > target){
                total -= i;
                i++;
            }else{
                int k = i;
                vector<int> tmp;
                while(k<j){
                    tmp.push_back(k++);
                }
                result.push_back(tmp);
                total-=i;
                i++;
            }
        }
        return result;
    }
};
