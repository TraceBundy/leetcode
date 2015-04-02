class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        vector<vector<int> > solution(m, vector<int>(n,0));
        solution[0][0] = 1;
        for (int i = 1; i < n; ++i){
            solution[0][i] = 1;
        }
        for (int i = 1; i < m; ++i){
            solution[i][0] = 1;
        }
        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                solution[i][j] = solution[i-1][j] + solution[i][j-1];
            }
        }
        return solution[m-1][n-1];
    }
};