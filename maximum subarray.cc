class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int max = 0;
        int end = 0;
        while (i < n) {
            if (i == 0){
                max = nums[i];
                end = max;
                j = i;
            } else if (max + nums[i] > nums[i] && j == i-1){
                max = max + nums[i];
                j = i;
            } else if (max < nums[i]){
                max = nums[i];
                j = i;
            }
            if (end < max) end = max;
            ++i;
        }
        return end;
    }
};