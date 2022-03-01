class Solution {
        // TC : O(N)
        // SC : O(10*N)
        // dp[n][x] ->  no. of distinct phone no. of length n ending with x
public:
    int knightDialer(int n) {
         const long long mod = 1e9 + 7;
         vector<vector<long long>>dp(n+1,vector<long long >(10,1));
        
          for(int i=2;i<=n;i++){
                  dp[i][0] = (dp[i-1][4] + dp[i-1][6]) % mod;
                  dp[i][1] = (dp[i-1][8] + dp[i-1][6]) % mod;
                  dp[i][2] = (dp[i-1][7] + dp[i-1][9]) % mod;
                  dp[i][3] = (dp[i-1][8] + dp[i-1][4]) % mod;
                  dp[i][4] = (dp[i-1][3] + dp[i-1][9]+dp[i-1][0]) % mod;
                  dp[i][5] = 0;
                  dp[i][6] = (dp[i-1][1] + dp[i-1][7] + dp[i-1][0]) % mod;
                  dp[i][7] = (dp[i-1][2] + dp[i-1][6]) % mod;
                  dp[i][8] = (dp[i-1][1] + dp[i-1][3]) % mod;
                  dp[i][9] = (dp[i-1][2] + dp[i-1][4]) % mod;
                                                      
          }
        return accumulate(dp[n].begin(),dp[n].end(),0l)%mod;
    }
};

// // Brute Force 
// class Solution {
//        //  TC : O(2^N)
//        //  SC : O(N + 10N) // N -> due to recursive stack space // 10N -> cache
//         const int mod = 1e9 +7;
//         map<string,int> mem;
//         vector<vector<int>>jumps;
        
//        int bt(int n, char c){
//                if(n==0) return 1;
//                string key = to_string(n) + "-" + c;
//                if(mem.find(key)!=mem.end()) return mem[key];
//                int ans = 0;
//                for(int i=0;i<jumps[c-'0'].size();i++){
//                      ans = (ans +  bt(n-1,jumps[c-'0'][i]+'0')) % mod;
                       
//                }
//                return mem[key]=ans;
//        } 
// public:
//     int knightDialer(int n) {
        
//             char c;
//             jumps = {
//                     {4,6},
//                     {8,6},
//                     {7,9},
//                     {8,4},
//                     {3,9,0},
//                     {},
//                     {1,7,0},
//                     {2,6},
//                     {1,3},
//                     {2,4}
//             };
//             long long ans=0;
//             for(int i=0;i<=9;i++){
                    
//                  ans = (ans + bt(n-1,'0'+i))% mod;
                   
//             }
//             return (int)ans;
//     }
// };