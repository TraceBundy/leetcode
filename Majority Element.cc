class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1) return nums[0];
        int i = 0;
        while (i < n){
            int j = i;
            while (j < n && nums[j] == nums[i]) ++j;
            if (j-i > n/2) return nums[i];
            i = j;
        }
    }
};