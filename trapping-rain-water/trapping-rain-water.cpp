class Solution {
public:
    int trap(vector<int>& nums) {
          
            int res=0;
            int n=nums.size();
            int left=0, right=n-1;
            int maxleft=0, maxright=0;
            
            while(left<right){
                    if(nums[left]<=nums[right]){
                            maxleft=max(maxleft,nums[left]);
                            res+=maxleft-nums[left];
                            left++;
                    }
                    else {
                            maxright=max(maxright,nums[right]);
                            res+=maxright-nums[right];
                            right--;
                    }
                    
            }
            return res;
    }
};