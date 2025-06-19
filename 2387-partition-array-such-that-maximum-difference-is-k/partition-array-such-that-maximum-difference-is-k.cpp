class Solution {
    // TC : O(N)
    // SC : O(1)
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            int j = i;
            while(j<n && nums[j]-nums[i]<=k){
                j++;
            }
            if(nums[j-1]-nums[i]<=k) cnt++;
            i = j-1;
        }
        return cnt;
    }
};