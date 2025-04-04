class Solution {
    // TC : O(N)
    // SC : O(N)
public:
    long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            vector<int>pre_max(n+1, 0), suff_max(n+1, 0);
            pre_max[0] = nums[0]; suff_max[n-1] = nums[n-1];
            for(int i=1;i<n;i++){
                pre_max[i] = max(pre_max[i-1], nums[i]);
            }
            for(int i=n-2;i>=0;i--){
                suff_max[i] = max(suff_max[i+1], nums[i]);
            }
            long long ans = 0;
            for(int i=1;i<n-1;i++){
                ans = max(ans, 1ll*suff_max[i+1]*(pre_max[i-1]-nums[i]));
            }
            return ans;
    }
};