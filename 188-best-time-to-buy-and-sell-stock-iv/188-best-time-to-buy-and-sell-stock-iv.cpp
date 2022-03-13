class Solution {
        // TC : O(K*N)
        // SC : O(K*N)
        
        // DP[k][i] -> max profit obtained till ith day by doing at most k transactions 
public:
    int maxProfit(int K, vector<int>& prices) {
        
            int n = prices.size();
            if(n<=1)return 0;
            
            vector<vector<int>> dp(K+1,vector<int>(n));
            
            int max_diff = -prices[0];
            
            for(int k=1;k<=K;k++)
            {
                    int max_diff = -prices[0];
                    for(int i=1;i<n;i++)
                    {
                        dp[k][i] = max(dp[k][i-1], prices[i]+max_diff);
                            
                        max_diff = max(max_diff, dp[k-1][i]-prices[i]);
                    }
            }
            
            return dp[K][n-1];
    }
};