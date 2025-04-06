class Solution {
    // TC : O(N)
    // SC : O(N)
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(2));
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
            dp[i][1] = -1;
        }
        int ans = 1;
        int idx = -1;
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(nums[j]%nums[i]==0){
                    if(dp[j][0] < 1+dp[i][0]){
                        dp[j][0] = 1 + dp[i][0];
                        dp[j][1] = i;
                    }
                }
            }
            if(ans < dp[j][0]){
                idx = j;
                ans = dp[j][0];
            }
        }
        if(ans==1) return {nums[0]};
        vector<int>res;
        while(idx!=-1){
            res.push_back(nums[idx]);
            idx = dp[idx][1];
        }
        return res;
       
    }
};