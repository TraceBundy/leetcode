class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        while (i < n){
            int j = i;
            while (j < n && nums[j] == nums[i]) ++j;
            if (j-1 == i) return nums[i];
            i = j;
        }
    }
};