class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() == 3)
            return num[0] + num[1] + num[2];
        sort(num.begin(), num.end());
        int min = abs(num[0] + num[1] + num[2] - target);
        int result;
        for (int i = 0; i < num.size()-2; ++i)
        {
            int j = i+1;
            int k = num.size()-1;
            while (j < k)
            {
                int sum = num[i] + num[j] + num[k];
                int temp = abs(sum - target);
                if (temp <= min)
                {
                    result = sum;
                    min = temp;
                }
                if (sum < target) j++;
                else k--;
            }
        }
        return result;
    }
};