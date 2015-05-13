class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string target;
        vector<string> result;
        string tmp(2*n,'.');
        stack<char> status;
        backtracking(result, tmp, status, 0, n);
        return result;
    }
    void backtracking(vector<string> &result, string &tmp, stack<char> &status, int k, int n){
        if (k == 2*n){
            if ( !status.empty()){
                return;
            }
            result.push_back(tmp);
            return;
        }
        tmp[k] = '(';
        status.push(tmp[k]);
        backtracking(result, tmp, status, k+1, n);
        if (!status.empty()) status.pop();;
        tmp[k] = ')';
        if (status.empty()) return;
        char c = status.top();
        status.pop();
        if( c != '(' ) return;
        backtracking(result, tmp, status, k+1, n);
        status.push(c);
    }
};