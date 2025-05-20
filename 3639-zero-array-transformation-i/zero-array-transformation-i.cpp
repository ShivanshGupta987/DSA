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
        
        if(nums[0]+temp[0]>0) return false;

        for(int i=1;i<n;i++){
            temp[i] += temp[i-1];
            if(nums[i]+temp[i]>0) return false;
        }
        return true;
    }
};