class Solution {
        // TC: O(K*N)
        // SC: O(K*N)
        // K-> MAX NO. OF TRANSACTIONS
        // N-> length of prices array
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
            int k=2;
            
            vector<vector<int>>dp(k+1,vector<int>(n,0));
            
            for(int i=1;i<=k;i++){
                    
                    int mindiff=prices[0];
                    for(int j=1;j<n;j++){
                            mindiff=min(mindiff,prices[j]-dp[i-1][j-1]);
                            dp[i][j]=max(dp[i][j-1],prices[j]-mindiff);
                            //cout<<dp[i][j]<<" ";
                           
                    }
                    cout<<endl;
            }
            return dp[2][n-1];
    }
};