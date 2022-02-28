// Matrix Exponentiation Method
// TC: O(log N)
// SC: O(log N)
class Solution {
    const int mod = 1e9 + 7;
           vector<vector<long long>> sq_mat ={
                        {1, 1, 2},
                        {1, 0, 0},
                        {0, 1, 1}
                        };
    const int size = 3 ;
     unordered_map<int,vector<vector<long long>>> mp ;

    
public : 
        vector<vector<long long>> matrix_Product(vector<vector<long long>> m1, vector<vector<long long>> m2){
             vector<vector<long long>> res=sq_mat; 
             for(int row=0; row<size; row++){
                     for(int col=0; col<size; col++){
                             long long  val = 0;
                             for(int k=0; k<size; k++){
                               val = (val + m1[row][k]*m2[k][col]) % mod;
                             }
                             res[row][col]=val;
                     }
             }
        return res;
}
     vector<vector<long long>> matrixExpo(int n){
             if(mp.find(n)!=mp.end()) return mp[n];
             
             vector<vector<long long>> res=sq_mat;
             if(n==1) res = sq_mat;
             else if(n%2) res =matrix_Product(matrixExpo(n-1),sq_mat);
             else res = matrix_Product(matrixExpo(n/2),matrixExpo(n/2));
             
             return mp[n]= res;
     }
   

    int numTilings(int n) {
        if(n<=2) return n;
           vector<long long> ans = matrixExpo(n-2)[0];
            return ((ans[0]*2 + ans[1]*1 + ans[2]*1 )%mod);
    }
};

















// class Solution {
//         // TC : O(N)
//         // SC : O(N)
//         const int mod = 1e9 + 7;
// public:
//     int numTilings(int n) {
//           // filled [i] ->no. of ways to tile ith col if there is no gap in (i+1)th col
//           // gap [i] -> no. of ways to tile ith col if there is a gap in (i+1)th col
//        vector<int>filled(n+1) , gap(n+1);
//             filled[n] = 1; 
//             for(int i=n-1; i>=0; i--){
//                    gap[i] = (gap[i+1]+ filled[i+1])%mod ;
//                    filled[i] = filled[i+1];
//                    if(i<n-1) filled[i] = (( filled[i] + 2ll*gap[i+2]) % mod +filled[i+2])%mod;
//             }
//             return filled[0];
//     }
// };

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