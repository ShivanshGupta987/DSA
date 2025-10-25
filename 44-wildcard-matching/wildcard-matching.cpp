class Solution {
    // TC : O(M*N)
    int dp[2001][2001];
    bool solve(int i, int j, string &s, string &t){
        int n = s.size(), m = t.size();
        if(j==m && i==n) return true;
        else if(i>n) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans = false;
        if(t[j]=='?'){
            ans |= solve(i+1, j+1, s, t);
        }
        else if(t[j]=='*'){
            ans |= solve(i+1, j, s, t); // taking '*' eq. to multiple char
            ans |= solve(i, j+1, s, t); // taking '*' eq. to empty string
        }
        else if(s[i]==t[j]){
            ans |= solve(i+1, j+1, s, t);
        }
        else ans |= false;
        return dp[i][j] = ans;
    }
public:
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, p);
    }
};