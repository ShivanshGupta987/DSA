class Solution {
        // TC : O(N)
        // SC : O(N)
public:
    int maxProfit(vector<int>& prices) {
          
            int n = prices.size();
            vector<int> cool(n), dp(n);
            
         // dp[i] -> max profit obtained till ith day by selling it either ith day or not selling it
        // cool[i] -> max profit obtained till ith day by cooling down at ith day 
            
            int max_diff = -prices[0];
            
            for(int i=1;i<n;i++)
            {       
                    
                    
                    // dp[i] = max(dp[i],prices[i]-prices[0]);
                    // for(int j=1;j<i;j++){
                    // dp[i] = max(dp[i],cool[j-1] + prices[i]-prices[j]);
                    // cool[i] = max(dp[i-1],cool[i-1]);
                    // }
                    
                    dp[i] = max(dp[i],prices[i] + max_diff);
                    
                    cool[i] =  max(dp[i-1] , cool[i-1]);
                    
                    max_diff = max(max_diff, cool[i-1] - prices[i]);
                    
            }
           return max(cool[n-1],dp[n-1]);
             
    }
};