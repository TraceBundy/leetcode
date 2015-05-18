class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string tmp;
        vector<string> result;
        if (digits.empty()) return result;
        vector<vector<char>> seq;
        make_letter(seq);
        vector<vector<char>> num;
        for (int i = 0; i < digits.length(); ++i){
            int k = digits[i] - 48 - 2;
            num.push_back(seq[k]);
        }
        backtracking(result, num, tmp, 0);
        return result;
    }
    void backtracking(vector<string> &result, vector<vector<char>> &num, string &tmp, int n){
        if (n == num.size()){
            result.push_back(tmp);
            return;
        }
        for (int i = 0; i < num[n].size(); ++i){
            tmp.push_back(num[n][i]);
            backtracking(result, num, tmp, n+1);
            tmp.pop_back();
        }
    }
    void make_letter(vector<vector<char>> &num){
        char letter = 97;
        for (int i = 2; i < 10; ++i){
            vector<char> tmp;
            if (i == 7 || i == 9){
                for (int j = 0; j < 4; ++j){
                    tmp.push_back(letter++);
                } 
            } else {
                for (int j = 0; j < 3; ++j){
                    tmp.push_back(letter++);
                }
            }
            num.push_back(tmp);
        }
    }
};