class Solution {
public:
    struct info{
        int x;
        int y;
    };
    void setZeroes(vector<vector<int>>& matrix) {
        vector<info> co;
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < matrix[0].size(); ++j){
                if (matrix[i][j] == 0){
                    info f = { i, j};
                    co.push_back(f);
                }
            }
        }
        for (int i = 0; i < co.size(); ++i){
            fillZero(matrix, co[i].x, co[i].y);
        }
    }
    void fillZero(vector<vector<int>>& matrix, int n, int m){
        for (int i = 0; i < matrix[n].size(); ++i){
            matrix[n][i] = 0;
        }
        for (int i = 0; i < matrix.size(); ++i){
            matrix[i][m] = 0;
        }
    }
};