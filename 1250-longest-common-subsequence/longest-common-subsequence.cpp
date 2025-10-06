class Solution {
    // TC : O(N*M)
    int dp[1001][1001];
    int rec(int i, int j, string & text1, string & text2){
        int n = text1.size(), m = text2.size();
        if(i==n || j==m) return dp[i][j] = 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if (text1[i] == text2[j]){
            ans = 1 + rec(i+1, j+1, text1, text2);
        }
        else{
            // skip i
            ans = max(ans, rec(i+1, j, text1, text2));

            // skip j 
            ans = max(ans, rec(i, j+1, text1, text2));
        }
        return dp[i][j] = ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof dp);
        return rec(0,0,text1, text2);
    }
};