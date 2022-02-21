class Solution {
        // TC: O(N)
        // SC: O(1)
public:
    int maxSubArray(vector<int>& nums) {
        long long max_so_far=nums[0],curr_max=nums[0];
            for(int i=1;i<nums.size();i++){
                    curr_max=max(curr_max+nums[i],(long long)nums[i]);
                    max_so_far=max(max_so_far,curr_max);
            }
            return (int)max_so_far;
    }
};