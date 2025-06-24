class Solution {
    // TC : O(N)
    // SC : O(1)
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        int n = nums.size();
        int right = 0;
        vector<int>res;
        for(int j=0;j<n;j++){
            if(nums[j]!=key) continue;
            int left = max(right, j-k);
            right = min(n-1, j+k) + 1;
            for(int i = left; i<right; i++){
                res.push_back(i);
            }
        }
        return res;
    }
};