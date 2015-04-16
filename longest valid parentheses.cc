class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        stack<int> p;
        for (int i = 0; i < len; ++i){
            if (s[i] == '('){
                p.push(i);
            }
            else if (!p.empty()){
                s[i] = '*';
                s[p.top()] = '*';
                p.pop();
            }
        }
        int max = 0;
        int cur = 0;
        for (int i = 0; i < len; ++i){
            cur = s[i] == '*' ? cur+1 : 0;
            if (cur > max) max = cur;
        }
        return max;
    }
};