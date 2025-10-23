class Solution {
    // TC : O(N*M)
    int dp[501][501];
    int INF = 501;
    int solve(int i, int j, string &s1, string &s2){
        int n = s1.size(), m = s2.size();
        if(i==n) return m-j;
        else if(j==m) return n-i;
        if(dp[i][j]!=-1) return dp[i][j];
        int cnt = INF;
        if(s1[i]==s2[j]){
            cnt = min(cnt, solve(i+1, j+1, s1, s2));
        }
        else{
            cnt = min(cnt, 1 + solve(i+1, j, s1, s2));
            cnt = min(cnt, 1 + solve(i, j+1, s1, s2));
        }
        return dp[i][j] = cnt;
    }
public:
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, word1, word2);
    }
};