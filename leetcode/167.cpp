class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> vec;
        if(numbers.size() < 2) return vec;
        int len = numbers.size();
        int index1 = 0, index2 = len - 1;
        
        while(index1 < index2){
            if(numbers[index1] + numbers[index2] == target){
                vec.push_back(index1+1);
                vec.push_back(index2+1);
                break;
            }else if(numbers[index1] + numbers[index2] < target){
                index1++;
                continue;
            } else {
                index2--;
                continue;
            }
        }

        return vec;

    }
};
