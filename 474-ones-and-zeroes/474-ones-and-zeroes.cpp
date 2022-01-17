class Solution {
public:
    int dp[601][101][101];
    pair<int,int> get_count(string &s)
    {
        int one = 0,zero = 0;
        for(char &ch : s)
        {
            if(ch=='0')
                zero++;
            else
                one++;
        }
        return {zero,one};
    }
    int dfs(int i,int a,int b,vector<string> &strings,int &m,int &n)
    {
        if(i==strings.size())return 0;
        if(dp[i][a][b]!=-1)return dp[i][a][b];
        auto [x,y] = get_count(strings[i]);
        if(a+x<=m && b+y<=n)
            dp[i][a][b] = max(dfs(i+1,a+x,b+y,strings,m,n)+1,dfs(i+1,a,b,strings,m,n));
        else
            dp[i][a][b] = dfs(i+1,a,b,strings,m,n);
        return dp[i][a][b];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,0,strs,m,n);
    }
};