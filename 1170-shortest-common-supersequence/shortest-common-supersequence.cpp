class Solution {
    // ---------- BOTTOM UP DP -----------
    // TC : O(N*M)
public:
    string shortestCommonSupersequence(string s1, string s2) {
        
        int dp[1001][1001] = {};
        int m = s1.size(), n = s2.size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s1[i] == s2[j]){
                    dp[i+1][j+1] = 1 + dp[i][j];
                }
                else{
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        string res = ""; // retrieving the answer using backtracking
        while(m && n){
            if(dp[m][n] == dp[m-1][n]){
                res += s1[--m]; // character only in s1
            }
            else if(dp[m][n] == dp[m][n-1]){
                res += s2[--n];  // character only in s2
            }
            else{
                // shared character in both s1 and s2
                // so we can take either of both
                res += s2[--n];
                --m;

                // or 
                // res += s1[--m];
                // --n;
            }
        }
        return s1.substr(0, m) + s2.substr(0, n) + string(rbegin(res), rend(res));
    }
};