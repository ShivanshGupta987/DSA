class Solution {
        // TC : O(N*K)
        // SC : O(N)
        
public:
    int maxSumAfterPartitioning(vector<int>& arr, int K) {
            int n = arr.size();
            vector<int>dp(n+1);
            
            for(int i=1; i<=n; i++){
                    int cur_max=0, best =0;
                    for(int k=1;k<=K && i-k>=0 ;k++){
                            cur_max = max(cur_max , arr[i-k]);
                            best = max(best, dp[i-k]+ cur_max*k);
                    }
                    dp[i]=best;
            }
            return dp[n];
    }
};




// class Solution {
// int dp[501]={};
//         // TC : O(n*K)
//         // SC : O(n)
// public:
//     int maxSumAfterPartitioning(vector<int>& arr, int k,int pos=0, int res=0) {
//         if(pos<arr.size() && dp[pos]!=0) return dp[pos];
//             for(int i=1, mv = 0; i<=k && i+pos<= arr.size(); i++){
//                     mv = max(mv, arr[pos+i-1]);
//                     res = max(res, mv*i + maxSumAfterPartitioning(arr,k,pos+i));
//             }
//             return dp[pos]=res;
//     }
// };