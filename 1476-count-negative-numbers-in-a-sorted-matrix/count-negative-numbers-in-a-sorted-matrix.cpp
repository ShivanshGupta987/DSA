class Solution {
    // TC : O(M+N)
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for(int i=m-1,j=0;i>=0;i--){
            while(j<n &&  grid[i][j] >= 0){
                j++;
            }
            cnt += n-j;
        }
        return cnt;
    }
};