class Solution {
    // TC : O(N*AMOUNT)
    // SC : O(N*AMOUNT)
    // N : COINS.SIZE

    int dp[301][5001];
    int solve(int idx, int amt, vector<int>& coins){
        int n = coins.size();
        if(amt==0) return 1;
        if(idx>=n || amt<0) return 0;
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int cnt = 0;
        cnt += solve(idx+1, amt, coins);
        cnt += solve(idx, amt-coins[idx], coins);
        return dp[idx][amt] = cnt;

    }
public:
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        int n = coins.size();
        sort(coins.begin(), coins.end());
        return solve(0, amount, coins);
    }
};