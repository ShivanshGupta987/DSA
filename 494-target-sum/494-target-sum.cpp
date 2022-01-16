//  ps -> sum of subset having positive sign
//  ns -> sum of subset having negative sign
 
//  ps-ns= target
//  ps+ns= sum
 
//  ps = (target+sum)/2
         
//  Hence, our problem got reduced to find out --
//          such  a subset ps
//          ps = (target +  sum)/2
// Also point to notice that ps is a integer hence value of  RHS must be 
// a integer. Hence, (target + sum) must be a even no.

class Solution {
        // Tabulaziation dp
        // TC:O(Sum*n)
        // Sum-> sum(nums)
        // n-> size(nums)
public:
    int findTargetSumWays(vector<int>& nums, int target) {
            int sum=0;
        for(int n: nums)sum+=n;
            
            if(sum<abs(target) || (target+sum)%2==1)return 0;
            int new_sum=(target+sum)/2;  
            // vector<int>dp(new_sum+1,0);
            // dp[0]=1;
            // for(int n:nums){
            //          for(int j=new_sum;j>=n;j--){
            //                 dp[j]+=dp[j-n]; 
            //                  cout<<dp[j]<<" ";
            //          }
            //         cout<<endl;
            // }
            // return dp[new_sum];
            
            
            int n=nums.size();
            vector<vector<int>>dp(n+1,vector<int>(new_sum+1,0));
            for(int i=0;i<n+1;i++)dp[i][0]=1;
            for(int i=1;i<n+1;i++){
                    for(int j=0;j<=new_sum;j++){
                         if(j==0 && nums[i-1]==0)dp[i][j]=2*dp[i-1][j];
 else if(nums[i-1]<=j) dp[i][j]+= (dp[i-1][j] + dp[i-1][j-nums[i-1]]);
         else dp[i][j]=dp[i-1][j];
                    }
            }
            for(auto x:dp){
                    for(auto y:x)cout<<y<<" ";
                    cout<<endl;
            }
            return dp[n][new_sum];
            
    }
};















// class Solution {
//         // TC: O(2^N)
//         // N ->  nums.size()
        
//         int dp(int ind, int target,int sum, vector<int>&nums,map<pair<int,int>,int>&mem){
                
//                 // Base cases
//              if(ind<0 && sum==target)return 1; 
//              if(ind<0)return 0;
//                 if(mem.find({ind,sum})!=mem.end())return mem[{ind,sum}];
                
//                 // decisions
                
//                 int positive = dp(ind-1,target,sum+nums[ind],nums,mem);
//                 int negative = dp(ind-1,target,sum-nums[ind],nums,mem);
//                 return mem[{ind,sum}]=positive + negative;
                
//         }
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//             map<pair<int,int>,int>mem;
//       return dp(nums.size()-1,target,0,nums,mem); 
           
//     }
// };