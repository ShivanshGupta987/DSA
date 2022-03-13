class Solution {
        // TC : O(N)
        // SC : O(N)
        
        // DP[i] -> max profit till ith day 
public:
    int maxProfit(vector<int>& prices, int fee) {
        
            int n = prices.size();
            vector<int>dp(n);
            
            int max_diff = -prices[0] - fee;
            for(int i=1;i<n;i++){
                    
                    dp[i] = max(dp[i-1], prices[i]+max_diff);
                    max_diff = max(max_diff , -prices[i]+dp[i]-fee);
            }
            return dp[n-1];
    }
};