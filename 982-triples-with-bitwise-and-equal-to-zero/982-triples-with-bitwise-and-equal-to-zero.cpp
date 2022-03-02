class Solution {
public:
        // TC : O(N^2)
        // SC : O(N^2)
    int countTriplets(vector<int>& nums) {
            unordered_map<int,int>mp;
            int n=nums.size();
            for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++) mp[nums[i] & nums[j]]++;
            
            int ans=0;
            
            for(auto &[k,v] : mp)
                    for(auto num : nums) if((num & k)==0) ans += v;
           
         return ans;
            
    }
};



// class Solution {
//         // TC : O(3* 2^16 * N)
//         // SC : (3* 2^16)
// public:
//     int countTriplets(vector<int>& nums) {
//         int M = 3;
//             int N = 1<<16;
//             vector<vector<int>>dp(M+1,vector<int>(N));
//             // dp[i][j] ->  No. of possible different combinations formed using first i elements having cumulative and value 'j'
//             dp[0][N-1]=1;
            
//             for(int i=0;i<M;i++){
//                     for(int j=0;j<N;j++){
//                             for(int num : nums){
//                                     dp[i+1][j & num] += dp[i][j];
//                             }
//                     }
//             }
//             return dp[M][0];
//     }
// };



// class Solution {
//         // TC : O(N^3)
//         // SC : O(1)
//         int ans = 0;
//    void bt(vector<int>&  nums, int i, int res){
//            int n=nums.size();
//            if(i==3) {  if(res == 0) ans++; return;}
//            if(res==0) {ans += pow(n,3-i); return;}
           
//            for(int num : nums){
//                    bt(nums,i+1,res & num);
//            }
//    }
// public:
//     int countTriplets(vector<int>& nums) {
//         bt(nums,0,pow(2,31)-1);
//             return ans;
//     }
// };