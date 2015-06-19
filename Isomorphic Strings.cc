class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> res;
        map<char, char> res2;
        int len = s.length();
        for (int i = 0; i < len; ++i){
            if (res.end() == res.find(s[i]) && res2.end() == res2.find(t[i])){
                    res[s[i]] = t[i]; 
                    res2[t[i]] = s[i];
            } else {
                if (t[i] != res[s[i]]){
                    return false;
                }
            }
        }
        return true;
    }
};