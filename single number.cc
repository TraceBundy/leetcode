class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        while (i < n-1){
            if (nums[i] == nums[i+1]) i += 2;
            else break;
        }
        return nums[i];
    }
};