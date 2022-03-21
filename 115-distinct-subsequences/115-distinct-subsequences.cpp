class Solution {
        // TC : O(N*M) // N -> t.size() ; M -> s.size()
        // SC : O(N*M)
public:
    int numDistinct(string s, string t) {
        
            
            vector<vector<unsigned long>>dp(t.size(),vector<unsigned long>(s.size()));
            dp[0][0] = (s[0]==t[0]); 
            
            for(int i=0;i<t.size();i++)
            {
                    
                    for(int j=i;j<s.size();j++)
                    {
                            if (i==0)
                            {
                                     if(j>0) dp[i][j] += dp[i][j-1] + (t[i]==s[j]);
                            }
                            else if(t[i]==s[j]) dp[i][j] += dp[i-1][j-1] + dp[i][j-1];
                            else  dp[i][j] = dp[i][j-1];
                    }
            }
            
            return dp.back().back();
    }
};