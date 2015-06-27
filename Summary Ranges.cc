class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        int cur = 1;
        int start = 0;
        vector<string> res;
        if (!n) return res;
        while (cur < n){
            if (nums[cur] != nums[cur-1]+1){
                string rang;
                if (cur != start+1){
                    rang += convert(nums[start]);
                    rang += "->";
                    rang += convert(nums[cur-1]);
                } else {
                    rang += convert(nums[start]);
                }
                start = cur;
                res.push_back(rang);
            }
            cur++;
        }
        string rang;
        if (cur != start+1){
            rang += convert(nums[start]);
            rang += "->";
            rang += convert(nums[cur-1]);
            start = cur;
        } else {
            rang += convert(nums[start]);
        }
        res.push_back(rang);
        return res;
    }
    string convert(int n){
        stringstream ss;
        ss << n;
        return ss.str();
    }
};