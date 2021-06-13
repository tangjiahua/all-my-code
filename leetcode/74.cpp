class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    int x = matrix.size();
    int y = matrix[0].size();
    
    for(int i = 0; i < x; i++){
        if (matrix[i][0] == target){
            return true;
        }
        if (matrix[i][0] < target){
            if(matrix[i][y-1] == target) return true;
            if(matrix[i][y-1] > target){
                for (int j = 0; j < y; j++){
                    if(matrix[i][j] == target) return true;
                }
                return false;
            } else {
                continue;
            }
        }
    }
    return false;
}
};
