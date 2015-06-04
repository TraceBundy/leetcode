class Solution {
public:
    bool isHappy(int n) {
        set<int> num;
        vector<int> res;
        num.insert(n);
        while (1){
            splitNum(n, res);
            n = sum(res);
            if ( n == 1){
                return true;
            } else if (isExist(num,n)){
                return false;
            }
            num.insert(n);
            res.clear();
        }
        
    }
    int sum(vector<int> &res){
       int sum = 0;
       for (int i = 0; i < res.size(); ++i){
           sum += res[i] * res[i];
       }
       return sum;
    }
    void splitNum(int n, vector<int> &res){
        while (n){
            int i = n % 10;
            res.push_back(i);
            n /= 10;
        }
    }
    bool isExist(set<int> &num, int n){
        return num.find(n) != num.end();
    }
};