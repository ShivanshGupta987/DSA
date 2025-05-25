class Solution {
    // TC : O(N)
    // SC : O(N)
    long long dp[(int)1e5][2];

    long long getMax(vector<int>& nums, int ind, int k, int isEven){
        int n = nums.size();
        if(ind==n) return isEven==1?0:INT_MIN;
        if(dp[ind][isEven]!=-1) return dp[ind][isEven];

        
        // doing xor on current index
        long long sum1 = (nums[ind]^k) + getMax(nums, ind+1, k, isEven^1);

        // not doing xor on current index
        long long sum2 = nums[ind] + getMax(nums, ind+1, k, isEven);

        return dp[ind][isEven] = max(sum1, sum2);
        
    }
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        memset(dp, -1, sizeof dp);
        return getMax(nums,0,k,1);
       
    }
};