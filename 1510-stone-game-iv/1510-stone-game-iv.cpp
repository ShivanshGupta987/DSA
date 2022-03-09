class Solution {
        // TC : O(N sqrt(N))
        // TC : O(N)
public:
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,false);
           
            for(int i=0;i<n;i++)
            {
                    if(dp[i]) continue;
                    for(int k=1; i+k*k <=n; k++) dp[i+k*k]=true;
                    
            }
            return dp[n];
    }
};




// class Solution {
//         // TC : O(N sqrt(N))
//         // SC : O(N)
//         unordered_map<int,bool>dp;
// public:
//     bool winnerSquareGame(int n) {
//         if(n==1) return true;
//         if(n==0) return false;
//         if(dp.find(n)!=dp.end()) return dp[n];
//         int x = sqrt(n);
//         if(pow(x,2)==n) return true;
            
//             for(int i=1;i<=sqrt(n);i++){
//                if(!winnerSquareGame(n-i*i))return true;  
//             }
            
//             return dp[n]=false;
//     }
// };