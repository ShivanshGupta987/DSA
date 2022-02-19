class Solution {
        //TC: O(N)
        // SC:O(1)
public:
    int majorityElement(vector<int>& nums) {
        int candidate=-1,votes=0;
            for(int i=0;i<nums.size();i++){
                    if(votes==0) candidate=nums[i];
                   
                    if(candidate==nums[i])votes++;
                    else votes--;     
            }
            return candidate;
    }
};