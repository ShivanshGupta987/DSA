// As we can observe that if want to find out least no. of perfect squares to sum up n. 
// then Subproblem can be defined as --
// Find out least no. of perfect squares to sum up x ;1<=x<=n

// There are overlapping subproblem hence this problem can be solved by dp 

// TC: O(N^2)
// SC:O(N)
class Solution {
public:
    int numSquares(int n) {
            vector<int>least_req_per_square(n+1,INT_MAX);
            least_req_per_square[0]=0;
            for(int i=1;i<=n;i++){
                    // to sum up i we me must have perfect square j*j  and some no. i-j*j(which can be perfect or non-perfect)
                    for(int j=1;j*j<=i;j++){
                            
                            least_req_per_square[i]=min(least_req_per_square[i],least_req_per_square[i-j*j]+1);
                    }
            }
            return least_req_per_square[n];
        
    }
};










// // Brute force soln
// class Solution {
//         int minn=INT_MAX;
//         private: 
//         void rec(int sum, int x, int steps=0 ){
//                 if(sum==0){
//                         minn=min(minn,steps);
//                         return;
//                 }
//                 for(int i=x;i>=1;i--){
//                         if(sum-i*i>=0)rec(sum-i*i,x,steps+1);
                        
//                 }
//         }
// public:
//     int numSquares(int n) {
//             rec(n,floor(sqrt(n)));
//         return minn;
//     }
// };