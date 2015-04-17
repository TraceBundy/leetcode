#include <vector>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

void search(string &A, int pos, int len, vector<string> &res){
    int left = pos-1;
    int right = pos+1;
    res.push_back(string(A,pos, 1));
    while (left >= 0 && right < len){
        if (A[left] == A[right]){
            int path = 0;
            while (pos - left - path >= 0){
                string sub;
                for (int i = left; i <= right; ++i){
                    if (i <= pos-path || i >= pos+path){
                        sub += A[i];
                    }
                }
                res.push_back(sub);
                ++path;
            }
        }
        ++right;
        --left;
    }
    left = pos-1;
    right = pos+1;
    if (right < len && A[pos] == A[right]){
        res.push_back(string(A, pos, 2));
        ++right;
        while (left >= 0 && right < len){
            if (A[left] == A[right]){
                int path = 0;
                while (pos - left - path > 0){
                    string sub;
                    for (int i = left; i <= right; ++i){
                        if (i <= pos-path || i > pos+path+1 || !path){
                            sub += A[i];
                        }
                    }
                    ++path;
                    res.push_back(sub);
                }
            }
            ++right;
            --left;
        }
    }
}


int main(int argc, char *argv[]){
    int len = strlen(argv[1]);
    string str(argv[1]);
    vector<string> res;
    for (int i = 0; i < len; ++i){
        search(str, i, len, res);
    }
    cout << "sum = " << res.size() << endl;
    for (int i = 0; i < res.size(); ++i){
        cout << res[i] << endl;
    }
    return 0;
}
