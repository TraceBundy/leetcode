class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        bool pre = true;
        int idx;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i-1]){
                if (pre){
                    return i-1;
                } else {
                    pre = false;
                }
            } else {
                pre = true;
            }
        }
        if (pre){
            return n-1;
        } else {
            return -1;
        }
    }
};