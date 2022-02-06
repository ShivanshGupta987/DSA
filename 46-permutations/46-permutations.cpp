class Solution {
public:
    void helper(vector<int>&nums, vector<int>& track, vector<vector<int>>& ret) {
        if(track.size() == nums.size()) {
            vector<int> tmp(track);
            ret.push_back(tmp);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            auto it = find(track.begin(), track.end(), nums[i]);
            if(it != track.end())
                continue;
            track.push_back(nums[i]);
            helper(nums, track, ret);
            track.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> track;
        helper(nums, track, ret);
        return ret;
    }
};