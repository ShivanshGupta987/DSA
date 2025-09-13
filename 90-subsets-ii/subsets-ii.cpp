class Solution {
    // TC : O(N*2^N)
    // SC : O(N*2^N) 
    void rec(vector<int>& nums, int idx, vector<int>& temp, vector<vector<int>>& res){
        
        res.push_back(temp);

        int n = nums.size();
        for(int i=idx; i<n;i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            rec(nums, i+1, temp, res);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        sort(nums.begin(), nums.end());
        rec(nums, 0, temp, res);
        return res;
    }
};