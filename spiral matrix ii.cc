class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n < 1) return vector<vector<int>>();
        vector<vector<int>> matrix(n,vector<int>(n,-1));
        int cur = 1;
        int i = 0, j = 0;
        matrix[0][0] = 1;
        while (cur < n*n){
            while (j+1 < n && matrix[i][j+1] == -1){
                matrix[i][++j] = ++cur;
            }
            while (i+1 < n && matrix[i+1][j] == -1){
                matrix[++i][j] = ++cur;
            }
            while (j-1 >= 0 && matrix[i][j-1] == -1){
                matrix[i][--j] = ++cur;
            }
            while (i-1 >= 0 && matrix[i-1][j] == -1){
                matrix[--i][j] = ++cur;
            }
        }
        return matrix;
    }
};