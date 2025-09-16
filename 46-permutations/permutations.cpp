class Solution {
    // TC : O(N*N!)
    // SC : O(N*N!)
    vector<vector<int>>res;
    void backtrack(vector<int>& nums, int ind, vector<int>& temp){
        int n = nums.size();
        if(ind==n){
            res.push_back(temp);
        }
        for(int i=ind; i<n;i++){
            temp.push_back(nums[i]);
            swap(nums[i], nums[ind]);
            backtrack(nums, ind+1, temp);
            swap(nums[i], nums[ind]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        backtrack(nums, 0, temp);
        return res;
    }
};