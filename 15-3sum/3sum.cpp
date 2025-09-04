class Solution {
    // TC : O(N log N)
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            if(nums[i]>0) break;
            if(i && nums[i]==nums[i-1])continue;
            int left = i+1, right = n-1;
            int target = -nums[i];
            while(left<right){
                if(nums[left] + nums[right] < target){
                    left++;
                    while(left<right && nums[left]==nums[left-1])left++;
                }
                else if(nums[left] + nums[right] > target){
                    right--;
                    while(left<right && nums[right]==nums[right+1])right--;
                }
                else{
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++; right--;
                    while(left<right && nums[left]==nums[left-1])left++;
                    while(left<right && nums[right]==nums[right+1])right--;
                }
            }
        }
        return res;
    }
};