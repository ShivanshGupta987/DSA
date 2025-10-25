class Solution {
    // TC : O(M*N)
    vector<vector<int>>dp;
    bool solve(int i, int j, int n, int m, string &s, string &t){
        if(j==m && i==n) return true;
        else if(i>n) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans = false;
        if(t[j]=='?'){
            ans |= solve(i+1, j+1, n, m, s, t);
        }
        else if(t[j]=='*'){
            ans =  solve(i+1, j, n, m, s, t) // taking '*' eq. to multiple char
                || solve(i, j+1, n, m, s, t); // taking '*' eq. to empty string
        }
        else if(s[i]==t[j]){
            ans |= solve(i+1, j+1, n, m, s, t);
        }
        else ans |= false;
        return dp[i][j] = ans;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
        return solve(0, 0, n, m, s, p);
    }
};