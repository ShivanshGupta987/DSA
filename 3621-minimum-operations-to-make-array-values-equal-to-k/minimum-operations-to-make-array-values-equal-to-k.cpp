class Solution {
    // TC : O(N* log N)
    // SC : O(1)
    // N : SIZE OF THE NUMS ARRAY
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums[0]<k) return -1;
        int grps = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int j = i;
            while(j+1<n && nums[j]==nums[j+1])j++;
            grps++;
            i = j;
        }
        if(nums[0]==k) return grps-1;
        else return grps;
    }
};