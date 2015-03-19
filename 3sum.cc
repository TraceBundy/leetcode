class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        int n = num.size();
        vector <vector<int> > result;
        int last[2] = {0};
        for (int i = 0; i < n-2; ++i)
        {
            int j = i+1;
            int k = n-1;
            while (j < k)
            {
                if (num[i] + num[j] + num[k] == 0)
                {
                    if (last[0] != num[i] && last[1] != num[j])
                    {
                        result.push_back({num[i], num[j], num[k]});
                        last[0] = num[i];
                        last[1] = num[j];
                        ++j;
                        --k;
                    }
                }
                else if (num[i]+ num[j] + num[k] < 0)
                {
                    ++j;
                }
                else 
                {
                    --k;
                }
            }
        }
        return result;
    }
};