class Solution {
        // TC : O(N)
        // SC : O(N)
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        
            int n= arr.size();
            unordered_map<int,int>mp;
            int res = 1;
            for(int i=0;i<n;i++){
                    if(mp.count(arr[i]-diff)) mp[arr[i]]= mp[arr[i]-diff]+1;
                    else mp[arr[i]]=1;
                    
                    res = max(res,mp[arr[i]]);
            }
            return res; 
    }
};





// BRUTE FORCE

// class Solution {
//         // TC : O(N*N)
//         // SC : O(N)
// public:
//     int longestSubsequence(vector<int>& arr, int diff) {
        
//             int n = arr.size();
//             int ans = 1;
//             vector<int>dp(n,1);
            
//             // dp[i] -> length of  longest arithemetic subsequence which ends with ith index element, using first i+1 elements 
//             for(int i=0;i<n;i++){
                    
//                     int j=i-1;
//                     while(j>=0){
//                             if(arr[i]-arr[j]== diff) {
//                                     dp[i] = max(dp[j]+1,dp[i]);
//                                     break;
//                             }
//                             j--;
//                     }
//                     ans = max(ans,dp[i]);
//             }
//             return ans;
//     }
// };