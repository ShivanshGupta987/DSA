// --------- SORTING BASED ----------
class Solution {
    // TC : O(n log n)
    // SC : O(1)
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt1 = 0, cnt2 = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i==0 || nums[i]==nums[i-1])cnt1++;
            else{
                cnt2 = (nums[i]==nums[i-1]+1)?cnt1 : 0, cnt1 = 1;
            }
            if(cnt1>0 && cnt2>0) ans = max(ans, cnt1+cnt2);
        }
        return ans;
    }
};



// --------------- HASH MAP BASED APPROACH ---------------
class Solution1 {
    // TC : O(N)
    // SC : O(N)
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int ans = 0;
        for(int x : nums){
            mp[x]++;
        }
        for(int i=0;i<n;i++){
            int  x = nums[i];
            if(mp.find(x+1)!=mp.end())ans = max(ans, mp[x] + mp[x+1]);
        }
        return ans;
    }
};