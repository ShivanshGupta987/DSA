class Solution {
public:
        // TC : O(N)
        // SC : O(N)
    
    int countNumbersWithUniqueDigits(int n) {
            static vector<int> dp(9,-1);
            if(dp[n]!=-1)return dp[n];
            dp[0]=1;
            int x=9,y=9;
            for(int i=1;i<=n;i++){
                dp[i]=x+dp[i-1];
                    x*=y; y-=1;
            }
            return dp[n];
    }
};