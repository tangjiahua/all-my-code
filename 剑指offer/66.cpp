class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int size = a.size();
        vector<int> result(size, 1);
        int left = 1;
        for(int i = 0; i < size; i++){
            result[i] = left;
            left *= a[i];
        }
        int right = 1;
        for(int i = size-1; i >= 0; i--){
            result[i] *= right;
            right *= a[i];
        }
        return result;
    }
};
