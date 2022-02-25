class Solution {
        // TC : O(N*S)
        // SC : O(N)
        // N -> Total no. of coins 
        // S -> Amount
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp (amount+1,0);
            dp[0]=1;
            for(int coin: coins){
                    for(int s=1;s<dp.size();s++){
                            if(s>=coin) dp[s]+=dp[s-coin];
                    }
            }
            return dp[amount];
            
    }
};