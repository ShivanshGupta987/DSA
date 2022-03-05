class Solution {
        // TC : O(N)
        // SC : O(1)
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>dp(3);
            // dp[0] -> max sum which is divisble by 3
            // dp[1] -> max sum when divided by 3 , rem =1
            // dp[2] -> max sum when divided by 3 , rem =2
            
            for(int num : nums){
                    for(int x : vector<int>(dp)) {
                            dp[(x+num)%3] = max(dp[(x+num)%3] , x+num);
                    }
            }
            return dp[0];
    }
};








// class Solution {
//         // TC : O(N * SUM)
//         // SC : O(SUM)
//         // SUM -> total sum of nums array
// public:
//     int maxSumDivThree(vector<int>& nums) {
            
//             int sum = accumulate(nums.begin(),nums.end(),0);
            
//             vector<bool>dp(sum+1,false);
//             dp[0]=true;
//             int ans =0;
//             for(int i=0;i<nums.size();i++){
//                     for(int s=sum; s>=nums[i]; s--){
//                             if(dp[s-nums[i]]) dp[s]=true;
//                             if(dp[s] && s%3==0) ans = max(ans,s);
//                     }
//             }
           
//            return ans ; 
//     }
// };