class Solution {
    // TC : O(N)
    // SC : O(N)
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>last_idx;
        int n = nums.size();
        vector<int>pre(n+1);
        int ans = nums[0];
        pre[1] = nums[0];
        last_idx[nums[0]] = 0;
        int start_idx = 0; 
        for(int i=1;i<n;i++){
            pre[i+1] += pre[i]+nums[i];
            if(last_idx.find(nums[i])!= last_idx.end() && last_idx[nums[i]] >= start_idx){
                start_idx = last_idx[nums[i]]+1;
            }
            last_idx[nums[i]] = i;
            // cout<<"("<<i<<","<<sum<<","<<start_idx<<")\n";
            ans = max(ans, pre[i+1]-pre[start_idx]);
        }
        return ans;
    }
};