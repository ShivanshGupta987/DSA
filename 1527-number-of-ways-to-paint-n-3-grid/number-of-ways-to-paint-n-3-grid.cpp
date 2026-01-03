class Solution {
    int n;
    int mod = 1e9 + 7;
    int dp[5002][4][4][4];
    bool isValid(int p1, int p2, int p3, int c1, int c2, int c3){
        return (c1!=p1 && c2!=c1 && c2!=p2 && c3!=c2 && c3!=p3);
    }
    long long solve(int idx, int prev1, int prev2, int prev3){
        if(idx==n+1) return 1;
        if(dp[idx][prev1][prev2][prev3] != -1) return dp[idx][prev1][prev2][prev3];

        long long ans = 0;
        for(int col1=0;col1<3;col1++){
            for(int col2=0;col2<3;col2++){
                for(int col3=0;col3<3;col3++){
                    if(isValid(prev1, prev2, prev3, col1, col2, col3)){
                        ans = (ans + solve(idx+1, col1, col2, col3))%mod;
                    }
                }
            }
        }
        return dp[idx][prev1][prev2][prev3] = ans%mod;
    }
public:
    int numOfWays(int n) {
        this->n = n;
        memset(dp, -1, sizeof dp);
        return solve(1, 3,3,3);
    }
};