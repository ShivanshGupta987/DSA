class Solution {
        // Tabulation Approach
        // TC: O(N)
        // SC: O(N)
public:
    int rob(vector<int>& nums) {
            if(nums.size()==1)return nums[0];
        vector<int>dp(nums);
            dp[1]=max(nums[0],nums[1]);
            for(int i=2;i<size(nums);i++){
                    dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
            }
            return dp[nums.size()-1];
    }
};


// class Solution {
//         // One - Liner Solution
// public:
//     int dp[101]{[0 ... 100]=-1};
//     int rob(vector<int>& nums,int i=0) {
//         return i<size(nums)?dp[i]!=-1?dp[i]:dp[i]=max(rob(nums,i+1),rob(nums,i+2)+nums[i]):0;
//     }
// };


// class Solution {
//          // Memoziation Approach
//         // TC: O(N)
//         // SC: O(N) ->space taken by implicit recursive stack
//         // N-> max depth of recursion
        
//         private: 
//         int dp(vector<int>&nums,vector<int>&mem,int i){
//                 if(size(nums)<=i)return 0;
//                 if(mem[i]!=-1)return mem[i];
//                 return mem[i]=max(dp(nums,mem,i+1),dp(nums,mem,i+2)+nums[i]);
//         }
// public:
//     int rob(vector<int>& nums) {
//         if(!nums.size())return 0;
//             vector<int>mem(nums.size(),-1);
//             return dp(nums,mem,0);
            
//     }
// };




// class Solution {
// public:
//     int rob(vector<int>& nums) {
//             // TC:O(N)
//      int ans=0;
//             int x=0,y=0;
//             for(int i=0;i<nums.size();i+=2){
//                x+=nums[i] ;   
//             }
//             for(int j=1;j<nums.size();j+=2){
//                     y+=nums[j];
//             }
//             return ans=max(x,y);
//     }
// };