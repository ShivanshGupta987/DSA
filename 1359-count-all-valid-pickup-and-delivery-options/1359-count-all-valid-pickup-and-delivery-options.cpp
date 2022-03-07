class Solution {
        // TC : O(N)
        // SC : O(N)
        
        
   const int mod = 1e9 + 7;
public:
    int countOrders(int n) {
         vector<int>dp(n+1);
            dp[1]=1;
            for(int i=2;i<=n;i++){
                    long long  x = 2*(i-1);
                     x = ((x+1)*(x+2))%mod;
                     x /=2;
                    dp[i] = (x*dp[i-1])%mod;             
            }
            return dp[n];
    }
};