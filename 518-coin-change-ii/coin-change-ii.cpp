class Solution {
    // TC : O(N*AMOUNT)
    // SC : O(N*AMOUNT)
    // N : COINS.SIZE

    int dp[301][5001];
    int rec(int idx, int amt, vector<int>& coins){
        int n = coins.size();
        if(amt==0) return 1;
        if(idx>=n) return 0;
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int cnt = 0;
        int j = 0;
        while(j*coins[idx] <= amt){
            cnt += rec(idx+1, amt-j*coins[idx], coins);
            j++;
        }
        return dp[idx][amt] = cnt;

    }
public:
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        int n = coins.size();
        sort(coins.begin(), coins.end());
        return rec(0, amount, coins);
    }
};