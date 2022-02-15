// DP + BIT MANIPULATION
// TC : O(N*(2^N))
// SC : (2^N)

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
            
            int n=nums.size();
            int sum = accumulate(nums.begin(),nums.end(),0);
            if((sum%k)!=0  || k>n)return false;
            int target =sum/k;
            
            int dp[1<<n];
            memset(dp,-1,sizeof(dp));
            dp[0]=0;
            
            for(int mask=0;mask<(1<<n);mask++)
            {
                    if(dp[mask]==-1)continue;
                    for(int i=0;i<n;i++)
                    {
                         if(!(mask & (1<<i)) && dp[mask]+nums[i]<=target)
                         {
                         dp[mask|(1<<i)]= (dp[mask]+nums[i])%target;                                }
                    }
            }
            return dp[(1<<n)-1]==0;
      }
};


// // Brute Force
// class Solution {
//         // TC: O(N!)
//         // SC:O(1)
//    int total;
//         bool helper(vector<int>&nums,int ind,int k,int sum){
//                 if(sum==0)return helper(nums,0,k-1,total);
//                 if(k==1)return true;
//                 if(ind==nums.size())return false;
//                 for(int i=ind;i<nums.size();i++){
//                         if(nums[i]!=INT_MAX && sum-nums[i]>=0){
//                                 int temp=nums[i];
//                                 nums[i]=INT_MAX;
//                         if(helper(nums,i+1,k,sum-temp))return true;
//                                 nums[i]=temp;
//                         }
//                 }
//                 return false;
//         }
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//          total =accumulate(nums.begin(),nums.end(),0);
//         if((total%k)!=0 || k>nums.size())return false;
//         total/=k;
            
//        return helper(nums,0,k,total);
//     }
// };