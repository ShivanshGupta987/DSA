// ---------- DYNAMIC PROGRAMMING --------
class Solution {
    // TC : O(N^2)
    // SC : O(N)
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        int ans = 1;
        for(int end=0;end<n;end++){
            for(int start=0; start<end;start++){
                if(nums[start] < nums[end]) dp[end] = max(dp[end], 1 + dp[start]);
            }
            ans = max(ans, dp[end]);
        }
        return ans;
    }
};

// ---------- BINARY SEARCH --------

class Solution1 {
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