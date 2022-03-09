class Solution {
public:
    string largestNumber(vector<int>& cost, int t) {
        
            vector<string>dp(t+1,"0");
            dp[t]="";
            
            for(int i=t-1;i>=0;i--){
                    for(int n=1;n<=9;n++){
                            int val = i + cost[n-1];
                            if(val <=t && dp[val]!="0")
                                    if(dp[val].size()+1 >= dp[i].size())
                                            dp[i] = to_string(n) + dp[val];
                    }
            }
            return dp[0];
    }
};






// class Solution {
//         // TC : O(N*target)
//         // SC : O(N*target)
   
//     string helper(vector<int>& cost, int ind, int target, vector<vector<string>>& dp){
            
//             if(target==0) return "";// success
//             if(target<0 || ind>=cost.size()) return "0"; // failure
            
//             if(dp[ind][target]!="-1") return dp[ind][target];
            
//             string include_it = to_string(ind+1) + helper(cost,0,target-cost[ind],dp);
//             string exclude_it = helper(cost,ind+1,target,dp);
            
//             return dp[ind][target] = getBigger(include_it,exclude_it);
//     }
        
//     string getBigger(string& s1, string& s2){
//             string t = "0";
//             if(s1.find(t) != string :: npos) return s2;
//             if(s2.find(t) != string :: npos) return s1;
//             if(s1.size() > s2.size()) return s1;
//             else return s2;
//     }    
// public:
//     string largestNumber(vector<int>& cost, int target) {
//             vector<vector<string>>dp(cost.size()+1,vector<string>(target+1,"-1"));
            
//             return helper(cost,0,target,dp);
            
//     }
// };