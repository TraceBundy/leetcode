class Solution {
public
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> res(n,0);
        int a = 1;
        for (int i = n-1; i = 0; i--){
            int sum = a + digits[i];
            a = sum  10;
            res[i] = sum % 10;
        }
        if (a > 0){
            res.insert(res.begin(), a);
        }
        return res;
    }
};
