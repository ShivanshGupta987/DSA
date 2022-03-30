class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
     
            int n = s.size();
            unordered_set<string>words;
            for(auto &x : wordDict) words.insert(x);
            
            vector<vector<string>>dp(n+1,vector<string>());
            dp[n].push_back("");
            // dp[i] -> vector of strings starting from index i to end of the string
            
            for(int i=n-1; i>=0; i--){
                    vector<string>values;
                    for(int j=i+1; j<=n; j++){
                            string str = s.substr(i,j-i);
                            if(words.count(str)){
                                    for(int k=0; k< dp[j].size();k++){
                                            values.push_back(str + (dp[j][k].empty()?"":" ") + dp[j][k]);
                                    }
                            }
                    }
                    dp[i]= values;
            }
            return dp[0];
    }
};










// class Solution {
//         // TC : O(2^N)
//         // N -> s.size()
//         vector<string>ans;
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
       
//             unordered_set<string>ss;
//             for(auto x: wordDict) ss.insert(x);
//             dfs(0,s,ss,"");
//             return ans;
//     }
        
//     void dfs(int start, string s, unordered_set<string>& ss, string cur_str){
            
//             int len = s.size();
//             if(len==0) {
//                     ans.push_back(cur_str); return ;
//             }
            
//             for(int end=0; end<len; end++){
//                     string str = s.substr(0,end+1);
//                     if(ss.count(str)) {
//               dfs(end+1, s.substr(end+1),ss, cur_str + (cur_str.size()?" ":"") + str);
//                     }
//             }
//     }
// };