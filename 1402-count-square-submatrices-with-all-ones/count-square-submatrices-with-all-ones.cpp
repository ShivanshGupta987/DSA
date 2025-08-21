class Solution {
    // TC : O(M*N)
    // SC : O(M*N)
public:
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int cnt = 0;
        vector<vector<int>>dp(m+1, vector<int>(n+1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    dp[i+1][j+1] = min({dp[i][j+1], dp[i+1][j], dp[i][j]}) + 1;
                }
                cnt += dp[i+1][j+1];
                // cout<<dp[i+1][j+1]<<" ";
            }
            // cout<<"\n";
        }
        return cnt;
    }
};