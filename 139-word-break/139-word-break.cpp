class Solution {
        // DP APPROACH
        // TC : O(N*N)
        // N -> s.size()
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
            unordered_set<string>ss;
           
            for(auto & x: wordDict) ss.insert(x);
            
            int n = s.size();
            vector<bool>dp(n+1,false);
            // dp[i] = true ; implies s[0,i) is present in wordDict
            dp[0] = true;
            for(int i=1;i<=n;i++){
                    for(int j=0; j<i;j++){
                            if(dp[j] && ss.count(s.substr(j,i-j))) {
                                    dp[i]=true;
                                    break;
                            }
                    }
            }
            return dp[n];
    }
};


// class Solution {
//         // BRUTE FORCE 
//         // TC : O(2^N)
//         // SC : O(N)
//         // N -> s.size()
        
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
        
//             unordered_set<string> ss;
//             for(auto &x : wordDict)ss.insert(x);
            
//             return dfs(s,ss);
            
//     }
        
//         bool dfs(string s, unordered_set<string>& ss){
//                 int n = s.size();
//                 if(n==0) return true;
          
                
//                 for(int end = 0; end<n; end++){
                        
//                         string str = s.substr(0,end+1);
                        
//                         if((ss.count(str)) && dfs(s.substr(end+1),ss)){
//                                 return true;
//                         }
                        
                        
//                 }
                
//                 return false;
//         }
// };