class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int i = 1;
        while (i < n){
            if (nums[i] < nums[i-1]) return nums[i];
            ++i;
        }
        return nums[0];
    }
};