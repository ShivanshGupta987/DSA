class Solution {
        // TC : O(N*N)
        // SC : O(N)
public:
    int findLongestChain(vector<vector<int>>& pairs) {
         int n=pairs.size();
         sort(pairs.begin(),pairs.end());
         vector<int>dp(pairs.size(),1);
         
         for(int i=0;i<n;i++){
                 for(int j=0;j<i;j++){
                 if(pairs[j][1] < pairs[i][0]) dp[i] = max(dp[i],dp[j]+1);
                 }
         }
         return dp[n-1];
            
    }
};