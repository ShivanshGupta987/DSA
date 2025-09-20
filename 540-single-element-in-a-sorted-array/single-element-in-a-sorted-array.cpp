class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int left = 0, right = n-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    left = mid+1;
                }
                else right = mid-1;
            }
            else{
                if(nums[mid]!=nums[mid+1]){
                    left = mid+1;
                }
                else right = mid-1;
            }
        }
        return nums[left];
    }
};