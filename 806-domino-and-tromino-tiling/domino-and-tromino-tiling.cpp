// Brute Force

class Solution {
//         Different Tile Orientations 
        
//                 T1 ->     |   
//                           |
                
//                 T2 ->     — —
//                           
                
//                 T3 ->     —
//                          |
                
//                 T4 ->    |
//                           —
                
//                 T5 ->    —
//                           |
                
//                 T6 ->     |
//                          —
        
    int dp[1001][2]; 
    int mod = 1e9 + 7;
    int helper(int i, int n, bool previousGap){
            if(i>n) return 0;
            if(i==n) return !previousGap;
            if(dp[i][previousGap]!=-1) return dp[i][previousGap];
            long long res = 0;
            
            if(previousGap){
                    res += helper(i+1,n,false);// considering T5 or T6 acc to previous config
                    res += helper(i+1,n,true); // considering T2 
            }
            
            else {
                    res += helper(i+1,n,false); // using T1
                    res += helper(i+2,n,false); // using T2
                    res += 2*helper(i+2,n,true); // using T3 or T4
            }
            return dp[i][previousGap] = res%mod;
    }
public:
    int numTilings(int n) {
        memset(dp, -1, sizeof dp);
        return helper(0,n,false);
    }
};