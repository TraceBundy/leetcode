class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> tmp;
        backtracking(result, tmp, s);
        return result;
    }
    void backtracking(vector<vector<string>> &result, vector<string> &tmp, string s){
        if (!s.size()){
            result.push_back(tmp);
            return;
        }
        for (int i = 1; i <= s.size(); ++i){
            if (check(s, 0,i-1)){
                tmp.push_back(s.substr(0,i));
                backtracking(result, tmp, s.substr(i,s.size()-i));
                tmp.pop_back();
            }
        }
    }
    bool check(string &s, int i, int j){
        while (i < j){
            if (s[i] != s[j]){
                break;
            }
            ++i;
            --j;
        }
        if (i < j) return false;
        return true;
    }
};