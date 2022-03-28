class Solution {

        // TC : O(N*(2^N))
        // SC : O(N*N)
    vector<vector<string>> ans;

public:
    vector<vector<string>> partition(string s) {
        
            int n = s.size();
            vector<vector<bool>>dp(n,vector<bool>(n,false));
            vector<string>curr_list;
            
            dfs(curr_list, 0, s, dp);
            return ans;
            
    }
        
    void dfs(vector<string> & curr_list, int start, string & s, vector<vector<bool>> &dp){
            
            int n = s.length();
            if(start >= n) ans.push_back(curr_list);
            
            for(int end = start ; end<n ; end++){
                    if(s[start]==s[end] && (end-start <=2  || dp[start+1][end-1])){
                            dp[start][end] = true;
                            curr_list.push_back(s.substr(start, end-start+1));
                            dfs(curr_list, end+1, s, dp);
                            curr_list.pop_back();
                    }
            }
    }
};