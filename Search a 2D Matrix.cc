class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; ++i){
            if (target <= matrix[i][m-1]){
                row = i;
                break;
            } 
        }
        for (int i = 0; i < m; ++i){
            if (matrix[row][i] == target){
                return true;
            }
        }
        return false;
    }
};