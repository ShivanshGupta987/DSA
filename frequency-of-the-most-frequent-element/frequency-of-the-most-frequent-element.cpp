class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
            // TC: O(N)
            // SC:O(1)
            
            int ans=1;
            int i=0;
            long sum=k;
            sort(nums.begin(),nums.end());
            for(int j=0;j<nums.size();j++){
                    sum+=nums[j];
                    if(sum<(long)nums[j]*(j-i+1))sum-=nums[i++];
                    else ans=max(j-i+1,ans);
            }
            return ans;
    }
};