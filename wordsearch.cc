class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n, m;
        if (board.size()){
            n = board.size();
        } else {
            return false;
        }
        if (board[0].size()){
            m = board[0].size();
        } else {
            return false;
        }
        vector<int> status(n*m, 0);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (board[i][j] != word[0]) continue;
                status[i*m+j] = 1;
                int k = 1;
                bool flag = backtracking(board, n, m, i, j, word, k, status);
                status[i*m+j] = 0;
                if (flag) return true;
            }
        }
        return false;
    }
    bool backtracking(vector<vector<char>>& board, int n, int m, int i, int j, string &word, int pos, vector<int> &status){
        if (pos == word.length()){
            return true;
        }
        int direction[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
        for (int  k= 0; k < 4; ++k){
            int h = i + direction[k][0];
            int l = j + direction[k][1];
            if (h >= 0 && h < n && l >= 0 && l < m && status[h*m+l] == 0 && board[h][l] == word[pos]){
                status[h*m+l] = 1;
                bool flag = backtracking(board, n, m, h, l, word, pos+1, status);
                status[h*m+l] = 0;
                if (flag) return true;
            }
        }
        return false;
    }
};