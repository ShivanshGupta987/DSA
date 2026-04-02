class Solution {
    // TC : O(M*N)
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        int INF = -1e9;
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(3, INF)));
        dp[0][1][0] = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // don't skip 
                dp[i+1][j+1][2] = coins[i][j] +  max(dp[i+1][j][2], dp[i][j+1][2]);
                dp[i+1][j+1][1] = coins[i][j] +  max(dp[i+1][j][1], dp[i][j+1][1]);
                dp[i+1][j+1][0] = coins[i][j] +  max(dp[i+1][j][0], dp[i][j+1][0]);

                // skip 
                dp[i+1][j+1][2] = max(dp[i+1][j+1][2], max(dp[i+1][j][1], dp[i][j+1][1]));
                dp[i+1][j+1][1] = max(dp[i+1][j+1][1], max(dp[i+1][j][0], dp[i][j+1][0]));
               
            }
        }
        return max({dp[m][n][2], dp[m][n][1], dp[m][n][0]});
    }
};