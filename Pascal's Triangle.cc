class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> tmp(1,1);
        if (numRows >= 1) {
            res.push_back(tmp); 
        }
        for (int i = 1; i < numRows; ++i){
            vector<int> tmp2;
            for (int j = 0; j <= i; ++j){
                int sum = j > 0 ? tmp[j-1] : 0; 
                sum += j < i ? tmp[j] : 0;
                tmp2.push_back(sum);
            }
            res.push_back(tmp2);
            tmp = tmp2;
        }
        return res;
    }
};