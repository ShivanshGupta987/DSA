class Solution {
    // TC : O(M*N)
    // SC : O(M*N)
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    bool isValid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
    int solve(int x, int y, vector<vector<int>>& mat, vector<vector<int>>& dp){
        int m = mat.size(), n = mat[0].size();
        if(dp[x][y]!=-1) return dp[x][y];
        int ans = 1;
        for(int k=0;k<4;k++){
            int nx = x+dx[k], ny=y+dy[k];
            if(isValid(nx, ny, m, n) && mat[x][y]<mat[nx][ny]){
                ans = max(ans, 1 + solve(nx, ny, mat, dp));
            }
        }
        return dp[x][y] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int ans = 1;
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                ans = max(ans, solve(x,y,mat,dp));
            }
        }
        return ans;
    }
};