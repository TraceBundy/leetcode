class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        dungeon[n-1][m-1] = max(1, -dungeon[n-1][m-1]+1);
        for (int i = m-2; i >= 0; --i){
            dungeon[n-1][i] = max(1, -dungeon[n-1][i] + dungeon[n-1][i+1]);
        }
        for (int j = n-2; j >= 0; --j){
            dungeon[j][m-1] = max(1, -dungeon[j][m-1] + dungeon[j+1][m-1]);
        }
        for (int i = n-2; i >= 0; --i){
            for (int j = m-2; j >= 0; --j){
                dungeon[i][j] = max(1, -dungeon[i][j] + min(dungeon[i+1][j], dungeon[i][j+1]));
            }
        }
        return dungeon[0][0];
    }
};