class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        int n = num.size();
        vector <vector<int> > result;
        if (num.size() < 3) return result;
        int i = 0;
        while (i < n-2)
        {
            int j = i+1;
            int k = n-1;
            while (j < k)
            {
                if (num[i] + num[j] + num[k] == 0)
                {
                    result.push_back({num[i], num[j], num[k]});
                    ++j;
                    --k;
                    while (j < k && num[j] == num[j-1]) j++;
                    while (j < k && num[k] == num[k+1]) k--;
                }
                else if (num[i]+ num[j] + num[k] < 0)
                {
                    ++j;
                    while (j < k && num[j] == num[j-1]) j++;
                }
                else 
                {
                    --k;
                     while (j < k && num[k] == num[k+1]) k--;
                }
            }
            ++i;
            while (i < n-2 && num[i] == num[i-1]) i++;
        }
        return result;
    }
};