class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 1) return n;
        int i = 1, j = 1;
        while (j < n){
            if (A[j] != A[i-1]){
                A[i++] = A[j];
            }
            j++;
        }
        return i;
    }
};