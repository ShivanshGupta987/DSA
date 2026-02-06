class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int j = 0;
        int ans = n;
        for(int i=0;i<n;i++){
            while(j<n && (long)nums[j]<=(long)k*nums[i])j++;
            ans = min(ans, n-(j-i));
        }
        return ans;
    }
};