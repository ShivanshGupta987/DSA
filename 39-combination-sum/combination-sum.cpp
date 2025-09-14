class Solution {
    void backtrack(vector<int>& nums, int ind, int sum, vector<int>& temp, int target, vector<vector<int>>& res){
        int n = nums.size();
        if(ind>=n) return;
        if(sum==target){
            res.push_back(temp);
        }

        for(int i=ind;i<n;i++){
            if(target < sum + nums[i]) break;
            temp.push_back(nums[i]);
            backtrack(nums, i, sum+nums[i], temp, target, res);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, 0, temp, target, res);
        return res;
    }
};