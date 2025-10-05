class Solution {
    // TC : O(N log N)
    // SC : O(N)
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis;
        
        for(int i=0;i<n;i++){
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
            if(it==lis.end()){
                lis.push_back(nums[i]);
            }
            else{
                int ind = it - lis.begin();
                lis[ind] = nums[i];
            }
        }
        return lis.size();
    }
};