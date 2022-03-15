class Solution {
        // TC : O(K*N)
        // SC : O((K^2)*N)
        // K -> No. of non-overlapping subarray
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int len) {
            
            int n = nums.size();
            
            int sum = 0;
            int K=3;
            vector<int>subarray(n-len+1);
            for(int i=0,j=0; i<n; i++)
            {
                    sum += nums[i];
                    if(i<len-1) continue;
                    subarray[j++]=sum;
                    sum -= nums[i+1-len];
                    
            }
  
 vector<vector<pair<int,vector<int>>>>dp(K,vector<pair<int,vector<int>>>(n+1,{0,{}}));
            
            for(int i=0;i<K;i++){
                    for(int j = n-len; j>=0; j--){
                           
                            dp[i][j] = {subarray[j],{j}};
                            if(i>0) {
                               dp[i][j] = {subarray[j] + dp[i-1][j+len].first, {j}};
                               for(int l : dp[i-1][j+len].second)
                                       dp[i][j].second.push_back(l);
                            }
                            
                          if(dp[i][j].first < dp[i][j+1].first) dp[i][j] = dp[i][j+1];
                            
                            
                    }
            }
            
            
//             for(auto x: dp){
//                     for(auto y:x) {
//                             cout<<"{"<<y.first<<" , ";
//                             for(auto z:y.second)cout<<z<<" ";
//                             cout<<"}";
//                     }
//                     cout<<endl;
//             }
            
            
            
            return dp.back().front().second;
        
    }
};