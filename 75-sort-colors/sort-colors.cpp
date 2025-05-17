class Solution {
    // TC : O(N)
    // 2 0 2 1 1 0 
    

    // ---- 0 ------ ------ 1 --------  ------- 2 ---------- 
    //              i                 j                      k running 
        

public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = -1, j = -1;
        for(int k=0;k<n;k++){
            if(nums[k]==0){
                swap(nums[k], nums[++j]);
                swap(nums[j], nums[++i]);
            }
            else if(nums[k]==1){
                swap(nums[k], nums[++j]);
            }
        }

    }
};