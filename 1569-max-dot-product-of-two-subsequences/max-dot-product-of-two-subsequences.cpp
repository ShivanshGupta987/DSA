class Solution {
    int dp[501][501][2];
    int solve(int i, int j, int taken, vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size(), m = nums2.size();
        if(i>=n || j>=m) return taken?0:-1e9;
        else if(dp[i][j][taken]!=-1) return dp[i][j][taken];
        int ans = -1e9;
        // take it 
        ans = max(ans, nums1[i]*nums2[j] + solve(i+1, j+1, 1, nums1, nums2));

        // don't take it 
        ans = max(ans, solve(i+1, j, taken, nums1, nums2));

        ans = max(ans, solve(i, j+1, taken, nums1, nums2));
        return dp[i][j][taken] = ans;
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums1, nums2);
    }
};