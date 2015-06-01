class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (!n) return false;
        int i = 0;
        while (i < n){
            int j = i;
            while (j < n && nums[j] == nums[i]) ++j;
            if (j-1 > i) return true;
            i = j;
        }
        return false;
    }
};