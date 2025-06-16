class Solution {
    // TC : O(N)
    // SC : O(1)
public:
    int maximumDifference(vector<int>& nums) {
       
        int n = nums.size();
        int ans = -1;
        int premin = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] > premin) ans = max(ans, nums[i]-premin);
            premin = min(premin, nums[i]);
        }
        return ans;
    }
};