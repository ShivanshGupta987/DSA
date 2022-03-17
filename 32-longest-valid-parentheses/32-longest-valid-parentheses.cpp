// TC : O(N)
// SC : O(N)

class Solution {
public:
    int longestValidParentheses(string s) {
        
            int ans =0;
            int n = s.size();
            if(s.size()<=1) return 0;
            
            vector<int>dp(n);
            
            for(int i=1;i<n;i++){
                  
                    if(s[i]=='(') continue;
                    
                   if(s[i-1]=='('){
                           dp[i] = (i>=2 ? dp[i-2]: 0) + 2 ;
                   }
                    
                   else if (i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '('){
                           int ind = i-dp[i-1]-1; 
                            dp[i] = dp[i-1] + (ind>=1 ? dp[ind-1]:0) + 2;
                     }
                    
                    ans = max(ans, dp[i]);
            }
            return ans;
    }
};