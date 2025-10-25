class Solution {
    // TC : O(M*N)
    int dp[1001][1001];
    int solve(int i, int j, string &s, string &t){
        int n = s.size(), m = t.size();
        if(j==m) return 1;
        else if(i>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int cnt = 0;
        if(s[i]==t[j]){
            cnt += solve(i+1, j+1, s, t);
        }
        cnt += solve(i+1, j, s, t);
        return dp[i][j] = cnt;
    }
public:
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, t);
    }
};