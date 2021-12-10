class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     if(nums.size()==0)return 0;
     if(nums.size()==1)return 1;
     if(nums.size()==2){
             if(nums[0]==nums[1])return 1;
             else return 2;
     }
            int i=0,j=1;
            while(j<nums.size()){
                    if(nums[i]<nums[j]){
                          if(nums[i+1]<=nums[i]) swap(nums[++i],nums[j]);
                            else i++;
                    }
                    j++;
                   
            }           
            return i+1;
    }
};