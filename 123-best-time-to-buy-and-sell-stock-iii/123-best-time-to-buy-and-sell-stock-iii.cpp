class Solution {
        // TC:O(N*K)
        // SC:O(N*K)  
        // K-> total no. of tranasactions
public:
    int maxProfit(vector<int>& prices) {
        const int k=2;
        int n=prices.size();
        vector<vector<int>>dp(k+1,vector<int>(n,0));
       for(int i=1;i<=k;i++){
               int max_diff=-prices[0];
               for(int j=1;j<n;j++){   
                    dp[i][j]=max(dp[i][j-1],prices[j]+max_diff);
                    max_diff=max(max_diff,dp[i-1][j]-prices[j]);
               }
       }
      return dp[k][n-1];      
    }
};