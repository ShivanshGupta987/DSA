class Solution {
        // TC: O(N)
        // SC: O(N)
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int count =0;
            int sum=0;
            int n=nums.size();
            unordered_map<int,int>mp{{0,1}};
            for(int i=0;i<n;i++){
                    sum+=nums[i];
                    if(mp.find(sum-k)!=mp.end())count+=mp[sum-k];
                    mp[sum]++;
            }
            return count;
                   
    }
};