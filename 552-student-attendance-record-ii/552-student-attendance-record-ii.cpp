class Solution {
        // TC : O(N*2*3)
        // SC : O(N*2*3)
public:
    int checkRecord(int n) {
         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3)));
         dp[n] = {{1,1,1},{1,1,1}};  
          
         const int mod = (int) 1e9 + 7;
         
         for(int i=n-1; i>=0;i--){
                 for(int a=0; a<2; a++){
                         for(int l=0;l<3;l++){
                           dp[i][a][l] = dp[i+1][a][0];
                           if(a==0) dp[i][a][l] = (dp[i][a][l] + dp[i+1][a+1][0])% mod;
                           if(l<2) dp[i][a][l] = (dp[i][a][l] + dp[i+1][a][l+1]) % mod;
                         }
                 }
         }
         
            return dp[0][0][0];
    }
};







//  TC: O(2^N)

//class Solution {
//         const int mod  = (int)1e9+7;
//         int N;   
       
//     int dfs(int i, int absent, int late,vector<vector<vector<int>>>& mem){
//             if(i==N){return 1;} 
            
            
//             if(mem[i][absent][late]!=-1)return mem[i][absent][late];
//             int ans=0;
            
//             // choice 1 - absent
            
//             if(absent<1) ans = (ans + dfs(i+1,absent+1,0,mem)) % mod;
            
//             // choice 2 - late
            
//             if(late<=1)ans =( ans + dfs(i+1,absent,late+1,mem)) % mod;
           
//             // choice 3 - present 
            
//             ans = (ans + dfs(i+1,absent,0,mem)) % mod;
       
//             return mem[i][absent][late]=ans;
//     }
// public:
//     int checkRecord(int n) {
//             N=n;
//         vector<vector<vector<int>>>mem(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
//         return dfs(0,0,0,mem);
//     }
// };