class Solution {
    // TC : O(n)
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int cnt = 0;
        long long ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt++;
                ans += cnt;
            }
            else cnt = 0;
        }
        return ans;
    }
};