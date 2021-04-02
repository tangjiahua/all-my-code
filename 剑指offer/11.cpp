class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0, high = numbers.size() - 1, i = numbers.size()/2;
        while(low < high){
            i = (low+high)/2;
            if(numbers[i] < numbers[high]){
                high = i;
            }else if(numbers[i] > numbers[high]){
                low = i + 1;
                
            }else{
                high--;
            }
        }
        return numbers[low];
    }
};
