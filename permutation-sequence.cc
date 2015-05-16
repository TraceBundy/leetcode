ass Solution {
    public:
    string getPermutation(int n, int k) {
        int fact[10] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        int sum = fact[n];
        char num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        string result(n, '0');
        for (int i = n; i > 0; --i){
            int line = fact[i] / i;
            int m = k/line;
            if (k%line != 0) ++m;
            k -= line * (m-1);
            int flag = 1;
            int s = 0;
            for (int j = 1; j <= n; ++j){
                if (num[j] != '0'){
                    s++;
                    if (s == m){
                        s = j;
                        break;
                    }
            }
        }

        for (int j = s; j <= n; ++j){
            if (num[j] != '0'){
                result[n-i] = num[j];
                num[j] = '0';
                flag = 0;
                break;
            }
        }
        if (flag){
            for (int j = 1; j < s; ++j){
                if (num[j] != '0'){
                    result[n-i] = num[j];
                    num[j] = '0';
                    break;
                }
            }
        }
    }
    return result;
}
};
