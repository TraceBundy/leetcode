class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int pos = -1;
        vector<int> v;
        int left = -1; int right = -1;
        pos = search(A, 0, n, target);
        if (pos != -1){
            left = pos, right = pos;
            while (left >= 0){
                if (A[left] != target) break;
                --left;
            }
            while (right < n){
                if (A[right] != target) break;
                ++right;
            }
            v.push_back(++left);
            v.push_back(--right);
        }
        else{
            v.push_back(left);
            v.push_back(right);
        }
        return v;
    }
    int search(int A[], int low, int high, int target){
        int pos = -1;
        int min = 0;
        while (low <= high){
            min = (low+high) / 2;
            if (A[min] == target){
                pos = min;
                break;
            }
            else if (A[min] > target){
                high = min -1;
            }
            else{
                low = min + 1;
            }
        }
        return pos;
    }
};