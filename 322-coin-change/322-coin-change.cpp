class Solution {
        // Recurrence Relation -> optimal(F(S)) = optimal (F(S-Ci)) + 1 where i : [0,N)
public:
    int coinChange(vector<int>& coins, int amount) {
            int max = 100000;
            vector<int>dp(amount+1,max);
            dp[0]=0;
            for(int s=1; s<= amount ; s++){
                    for(int coin : coins){
                            if(s>=coin) dp[s] = min(dp[s],dp[s-coin]+1);
                    }
            }
            return dp[amount]==max ? -1 : dp[amount];
    }
};