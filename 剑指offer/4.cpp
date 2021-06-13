class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int row = 0, col = matrix[0].size()-1;
        while((row <= matrix.size()-1) && col >= 0 && matrix.size()){
            if(matrix[row][col] < target){
                row++;
            }else if(matrix[row][col] > target){
                col--;
            }else{
                return true;
            }
        }
        return false;
    }
};
