class Solution {
    // TC : O(N)
    // SC : O(N)
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int ans = 0;
        for(int x : nums){
            mp[x]++;
        }
        for(int i=0;i<n;i++){
            int  x = nums[i];
            if(mp.find(x+1)!=mp.end())ans = max(ans, mp[x] + mp[x+1]);
        }
        return ans;
    }
};