class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        select sel[2] = {{0,0},{0,0}};
        int n = nums.size();
        vector<int> res;
        if (n <= 1) return nums;

        for (int i = 0; i < n; ++i){
            if (sel[0].nums == nums[i]){
                sel[0].count++;
            } else if (sel[1].nums == nums[i]){
                sel[1].count++;
            } else if (sel[0].count == 0){
                sel[0].nums = nums[i];
                sel[0].count = 1;
            } else if (sel[1].count == 0){
                sel[1].nums = nums[i];
                sel[1].count = 1;
            } else {
                sel[0].count--;
                sel[1].count--;
            }
        }
		//candidate number
        int count1 = 0,  count2 = 0;
        for (int i = 0; i < n; ++i){
            if (sel[0].nums == nums[i]) count1++;
            else if (sel[1].nums == nums[i]) count2++;
        }
        if (count1 > n/3 ){
            res.push_back(sel[0].nums);
        }
        if (count2 > n/3){
            res.push_back(sel[1].nums);
        }
        return res;
    }
    struct select{
        int nums;
        int count;
    };
};