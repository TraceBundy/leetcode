class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int begin = 0;
        int end = 0;
        int i = 0;
        while (s[i] != '\0'){
            if (s[i] == ' '){
                while (s[i] == ' ') i++;
                if (s[i] != '\0') {
                    begin = i;
                    end = ++i;
                }
            }else{
                end = ++i;
            }
        }
        return end-begin;
    }
};