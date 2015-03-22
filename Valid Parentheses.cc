class Solution {
public:
    bool isValid(string s) {
        char left[3] = {'(', '{', '['};
        char right[3] = { ')', '}', ']'};
        stack<char> bts;
        for (int i = 0; i < s.length(); ++i)
        {
            int j = -1;
            if (s[i] == left[0] || s[i] == left[1] || s[i] == left[2]){
                bts.push(s[i]);
            }
            else if (s[i] == right[++j] || s[i] == right[++j] || s[i] == right[++j]){
                if (bts.empty()) return false;
                if (bts.top() == left[j]) bts.pop();
                else return false;
            }
        }
        return bts.empty() ? true : false;
    }
};