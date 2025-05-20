class Solution {
    // TC : O(N)
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>temp(n+1);
        for(auto & q : queries){
            temp[q[0]]--;
            temp[q[1]+1]++;
        }
        nums[0] += temp[0];
        if(nums[0]>0) return false;
        for(int i=1;i<n;i++){
            temp[i] += temp[i-1];
            nums[i] += temp[i];
            if(nums[i]>0) return false;
        }
        return true;
    }
};