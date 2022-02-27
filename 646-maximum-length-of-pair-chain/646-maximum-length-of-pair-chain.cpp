class Solution {
        // TC : O(N log N)
        // SC : O(1)
        // greedy approach
public:
    int findLongestChain(vector<vector<int>>& pairs) {
         int n=pairs.size();
         sort(pairs.begin(),pairs.end(),[] (const vector<int>& a, const vector<int>& b) {return a[1]<b[1];});
         vector<int>dp(pairs.size(),1);
          
         int cur = INT_MIN , ans=0;
         for(int i=0;i<n;i++){
              if(cur<pairs[i][0]) { cur = pairs[i][1] ; ans++;}   
         }
         return ans;
            
    }
};





//class Solution {
//         // TC : O(N*N)
//         // SC : O(N)
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//          int n=pairs.size();
//          sort(pairs.begin(),pairs.end());
//          vector<int>dp(pairs.size(),1);
//          for(int i=0;i<n;i++){
//                  for(int j=0;j<i;j++){
//                  if(pairs[j][1] < pairs[i][0]) dp[i] = max(dp[i],dp[j]+1);
//                  }
//          }
//          return dp[n-1];
            
//     }
// };