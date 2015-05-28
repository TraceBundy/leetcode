class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int Min[n][m];
        Min[0][0] = grid[0][0];
        for (int i = 1; i < n; ++i){
            Min[i][0] = Min[i-1][0]+grid[i][0];
        }
        for (int j = 1; j < m; ++j){
            Min[0][j] = Min[0][j-1]+grid[0][j];
        }
        for (int i = 1; i < n; ++i){
            for (int j = 1; j < m; ++j){
                Min[i][j] = min(Min[i-1][j], Min[i][j-1]) + grid[i][j];
            }
        }
        return Min[n-1][m-1];
    }
};