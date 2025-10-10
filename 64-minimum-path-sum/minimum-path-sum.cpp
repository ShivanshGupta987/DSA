class Solution {
    // TC : O(N*M)
    // SC : O(N*M)
    int INF = 1e5;
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, INF));
        dp[0][0] = grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i) dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
                if(j) dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
            }
        }
        return dp[n-1][m-1];
    }
};