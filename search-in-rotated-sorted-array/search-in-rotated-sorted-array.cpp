class Solution {
public:
    int search(vector<int>& nums, int target) {
            // TC:O(Log N)
            // SC:O(1)
            
            int n=nums.size();
            int k=0; // pivot index
            int low=0;
            int high=n-1;
            
            while(low<high){
                   int mid=low+(high-low)/2;
                if(nums[mid]>nums[high])low=mid+1;
                    else high=mid;
            }
            k=low;
            low=0;
            high=n-1;
            
            while(low<=high){
                    int mid=low+(high-low)/2;
                    int nmid=(mid+k)%n; // new rotated mid index
                    
                    if(target<nums[nmid])high=mid-1;
                    else if(target==nums[nmid])return nmid;
                    else low=mid+1;
            }
            return -1;
    }
};