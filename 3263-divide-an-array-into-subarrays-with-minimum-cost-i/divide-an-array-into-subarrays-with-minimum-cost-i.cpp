class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = 200;
        for(int k=0;k<n;k++){
            for(int j=1;j<k;j++){
                    ans = min(ans, nums[0]+nums[j]+nums[k]);
            }
        }
        return ans;
    }
};