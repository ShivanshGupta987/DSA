class Solution {
    // TC : O(N)
    // SC : O(N)
public:
    int maximumDifference(vector<int>& nums) {
        vector<int>st;
        int n = nums.size();
        int ans = -1;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.back() >= nums[i]){
                st.pop_back();
            }
            st.push_back(nums[i]);
            if(st.size()>1) ans = max(ans, st.back()-st[0]);
        }
        return ans;
    }
};