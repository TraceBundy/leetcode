class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        vector<int> status(num.size(), 0);
        vector<int> tmp(num.size(), 0);
        search(result, num, status, tmp, 0);
        return result;
    }
    void search(vector<vector<int> > &result, vector<int> &num,
				vector<int> &status,vector<int> &tmp, int k){
        if (k == num.size()){
            result.push_back(tmp);
        }
        for (int i = 0; i < num.size(); ++i){
            if (status[i] == 0){
                tmp[k] = num[i];
                status[i] = 1;
                search(result, num, status, tmp, k+1);
                status[i] = 0;
            }
        }
    }
};