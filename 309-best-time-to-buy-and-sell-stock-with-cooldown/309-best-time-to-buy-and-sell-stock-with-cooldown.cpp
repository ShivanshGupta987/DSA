class Solution {
        // TC : O(N*N)
        // SC : O(N)
public:
    int maxProfit(vector<int>& prices) {
          
            int n = prices.size();
            vector<int> cool(n), dp(n);
            
         // dp[i] -> max profit obtained till ith day 
            
            for(int i=1;i<n;i++)
            {       
                    dp[i] = max(dp[i],prices[i]-prices[0]);
                    for(int j=1;j<i;j++){
                    dp[i] = max(dp[i],cool[j-1] + prices[i]-prices[j]);
                    cool[i] = max(dp[i-1],cool[i-1]);
                    }
            }
           return max(cool[n-1],dp[n-1]);
             
    }
};