class Solution {
        // Iterative DP
        // TC : O(N)
        // SC : O(1)
        
        // dp[i] -> represents no. of ways to decode the substring starting from index i
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1);
        dp[n]=1;
         
        for(int i=n-1;i>=0;i--){
                if(s[i]=='0') dp[i]=0;
                else {
                        dp[i] = dp[i+1];
                        
                        if(i<n-1) {
                                int num = stoi(s.substr(i,2));
                                if(num>9 && num < 27) dp[i] += dp[i+2];
                        }
                }
                
        }
            return dp[0]; 
    }
};





























// class Solution {
        
//         // TC: O(N)
//         // SC: O(N)
//         // N-> size of string
//         private:
        
//         int rec(string &s,int i,vector<int>&mem){
//              if(mem[i]>-1) return mem[i]; 
//              if(s[i]=='0')return mem[i]=0;
                
//           int res=rec(s,i+1,mem);
        
//         if(i<s.size()-1){
//                 int num=stoi(s.substr(i,2));
//                 if(num>9 && num<27)res+=rec(s,i+2,mem);
//         }
//                 return mem[i]=res;
                
                
//         }
// public:
//     int numDecodings(string s) {
//              int n=s.size();
//             vector<int>mem(n+1,-1);
//             mem[n]=1;
//      return s.empty()?0:rec(s,0,mem);
            
//     }
// };