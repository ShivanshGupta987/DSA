class Solution {
    // TC : O(N log N + N*(TOTAL_SUM/2))
    int dp[201][20001];
    bool rec(int ind, int rem, vector<int>& nums){
        int n = nums.size();
        if(ind==n) return rem==0;
        if(rem<0) return false;
        if(dp[ind][rem] != -1) return dp[ind][rem];
        bool ans = false;
        // take it 
        ans |= rec(ind+1, rem-nums[ind], nums);

        // don't take it 
        ans |= rec(ind+1, rem, nums);
        
        return dp[ind][rem] = ans;
    }
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            total_sum += nums[i];
        }
        if(total_sum & 1) return false;
        memset(dp, -1, sizeof dp);
        return rec(0, total_sum/2, nums);
    }
};