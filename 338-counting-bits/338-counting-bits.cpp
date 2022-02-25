class Solution {
        // TC : O(N)
        
// ---------------- INTUTION BEHIND THE PROBLEM ------------------
        
//    Problem : To find out no. of setbits in given number n
         
//   # Case 1 # (if n is even)
//            no. of setbits in n = no. of setbits in n/2
//       Ex - 
//            10 = 1010
//            5  = 0101
//   # Case 2 # (if n is odd)
//            no. of setbits in n = (no. of setbits in n/2) + 1;   
//       Ex- 
//            11 = 1011
//             5 = 0101
public:
    vector<int> countBits(int n) {
        
            vector<int> dp(n+1);
            
            for(int i=0;i<=n;i++){
                  dp[i] = dp[i>>1] + (i&1);  
            }
            
            return dp;
    }
};


//class Solution {
//         // TC : O(N log N)
//         // SC : O(1)
//         void countSetBits(vector<int>& ans, int n){
//                 int x=n;
//                 while(x!=0)
//                 {
//                  ans[n]++; 
//                  x &= x-1; // diminshes the first setbit in x 
//                 }
//         }
// public:
//     vector<int> countBits(int n) {
//         vector<int> ans(n+1);
//             for(int i=0;i<=n;i++)countSetBits(ans,i);
//             return ans;
//     }
// };