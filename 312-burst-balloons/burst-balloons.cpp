class Solution {
    // TC : O(N^3)
    // SC : O(N^2)
    int dp[301][301];
    int solve(int i, int k, vector<int>& nums){
        int n = nums.size();
        // cout<<"("<<i<<","<<k<<")\n";
        if(i>k) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int ans = 0;
        for(int j=i;j<=k;j++){
            ans = max(ans, (i>0?nums[i-1]:1)*nums[j]*(k<n-1?nums[k+1]:1) + solve(i,j-1, nums) + solve(j+1, k, nums));
        }
        return dp[i][k] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return solve(0,n-1, nums);
    }
};