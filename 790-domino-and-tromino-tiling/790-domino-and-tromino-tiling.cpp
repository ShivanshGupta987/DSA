class Solution {
        // TC : O(N)
        // SC : O(N)
        const int mod = 1e9 + 7;
public:
    int numTilings(int n) {
          // filled [i] ->no. of ways to tile ith col if there is no gap in (i+1)th col
          // gap [i] -> no. of ways to tile ith col if there is a gap in (i+1)th col
       vector<int>filled(n+1) , gap(n+1);
            filled[n] = 1; 
            for(int i=n-1; i>=0; i--){
                   gap[i] = (gap[i+1]+ filled[i+1])%mod ;
                   filled[i] = filled[i+1];
                   if(i<n-1) filled[i] = (( filled[i] + 2ll*gap[i+2]) % mod +filled[i+2])%mod;
            }
            return filled[0];
    }
};

// // Brute Force

// class Solution {
// //         Different Tile Orientations 
        
// //                 T1 ->     |   
// //                           |
                
// //                 T2 ->     — —
// //                           
                
// //                 T3 ->     —
// //                          |
                
// //                 T4 ->    |
// //                           —
                
// //                 T5 ->    —
// //                           |
                
// //                 T6 ->     |
// //                          —
        
        
//     int helper(int i, int n, bool previousGap){
//             if(i>n) return 0;
//             if(i==n) return !previousGap;
            
//             int res = 0;
            
//             if(previousGap){
//                     res += helper(i+1,n,false);// considering T5 or T6 acc to previous config
//                     res += helper(i+1,n,true); // considering T2 
//             }
            
//             else {
//                     res += helper(i+1,n,false); // using T1
//                     res += helper(i+2,n,false); // using T2
//                     res += 2*helper(i+2,n,true); // using T3 or T4
//             }
//             return res;
//     }
// public:
//     int numTilings(int n) {
//         return helper(0,n,false);
//     }
// };