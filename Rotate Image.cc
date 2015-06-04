class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        for (int i = 0; i < n-1; ++i){
            for (int j = 0; j < n-i; ++j){
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
            }
        }
        for (int i = 0; i < n / 2; ++i){
            for (int j = 0; j < m; ++j){
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }
    }
    void swap(int &i, int &j){
        int tmp = j;
        j = i;
        i = tmp;
    }
};