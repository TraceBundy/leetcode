class Solution {
public:
    bool isPowerOfTwo(int n) {
        int num = n & (n-1);
        return n > 0 && num == 0;
    }
};