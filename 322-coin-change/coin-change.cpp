class Solution {
    // TC : O(AMOUNT*N)
    // SC : O(AMOUNT)
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1,-1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int amt=1; amt<=amount; amt++){
            for(int i=0; i<n && coins[i]<=amt; i++){
                if(dp[amt-coins[i]]!=-1){
                    if(dp[amt]==-1) dp[amt] = 1 + dp[amt-coins[i]];
                    else dp[amt] = min(dp[amt], 1 + dp[amt-coins[i]]); 
                }
            }
        }
        return dp[amount];
    }
};