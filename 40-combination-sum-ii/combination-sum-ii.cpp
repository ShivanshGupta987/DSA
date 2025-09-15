class Solution {
    // TC : O(N*2^N)
    // SC : O(N)
    vector<vector<int>>res;

    void backtrack(vector<int>& nums, int ind, int target, vector<int>& temp){
        if(target==0){
            res.push_back(temp);
        }
        int n = nums.size();
        for(int i=ind;i<n;i++){
            if(target-nums[i] < 0) break;
            if(i>ind && nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            backtrack(nums, i+1, target-nums[i], temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int>temp;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, target, temp);
        return res;
    }
};