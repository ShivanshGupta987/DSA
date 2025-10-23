class Solution {
    // TC : O(N*N)
    // SC : O(N*N)
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int end=0;end<n;end++){
            for(int start=end; start>=0;start--){
                if(start==end){
                    dp[start][end] = 1;
                }
                else{
                    dp[start][end] = max(dp[start][end], (s[start]==s[end]?2:0) + dp[start+1][end-1]);
                    dp[start][end] = max(dp[start][end], dp[start+1][end]);
                    dp[start][end] = max(dp[start][end], dp[start][end-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};