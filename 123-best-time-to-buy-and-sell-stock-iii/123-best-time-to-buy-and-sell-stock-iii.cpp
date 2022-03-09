class Solution {
        // TC : O(N*K)
        // SC : O(N*K)
        // N -> size(prices)
        // K -> No. of transactions
public:
    int maxProfit(vector<int>& prices) {
            int n = prices.size();
            vector<vector<int>>dp(3,vector<int>(n));
            for(int k=1;k<=2;k++)
            {
                    int maxx_diff = -prices[0];
                    for(int i=1;i<n;i++)
                    {
                         int max_profit = dp[k][i-1];
                        
                         // for(int j=0;j<i;j++)
                         // {
                         // max_profit= max(max_profit, prices[i]-prices[j]+ dp[k-1][j]);
                         // }
                         max_profit = max(max_profit, prices[i] + maxx_diff);
                         dp[k][i]= max_profit;
                         maxx_diff = max(maxx_diff , -prices[i] + dp[k-1][i]);
                    }
                    
            }
            
            return dp[2][n-1];
    }
};