class Solution {
    // TC : O(N)
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int total_sum_mod = 0;
        for(int x : nums){
            total_sum_mod = (total_sum_mod+x) % p;
        }
        unordered_map<int,int>mp;
        mp[0] = -1;
        int n = nums.size();
        int ans = n;
        int sum = 0;
        for(int j=0;j<n;j++){
            sum = (sum+nums[j])%p;
            mp[sum] = j;
            int target = (sum-total_sum_mod+p)%p;
            if(mp.find(target)!=mp.end()){
                ans = min(ans, j-mp[target]);
            }
        }
        return ans==n?-1:ans;

    }
};