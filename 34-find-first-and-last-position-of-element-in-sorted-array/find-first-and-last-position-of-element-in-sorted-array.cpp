class Solution {
    // TC : O(N)
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int n = nums.size();
        int l = -1, r = n;
        while(l+1<r){
            int mid = (l+r)/2;
            // predicate(mid)==0
            if(nums[mid]<target){
                l = mid;
            }
            else r = mid;
        }
        if(r!=n && nums[r]==target){
            ans[0] = r;
        }

        l=-1, r=n;

        while(l+1<r){
            int mid = (l+r)/2;
            // predicate(mid)==0
            if(nums[mid]<=target){
                l=mid;
            }
            else r=mid;
        }
        if(l!=-1 && nums[l]==target){
            ans[1] = l;
        }
        return ans;

    }
};