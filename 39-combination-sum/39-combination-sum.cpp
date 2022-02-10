class Solution {
public:
        // N->nums.size()
        // min_nums->min(nums)
        // TC : O(N^(min_nums +1) * (Target/min_nums))   
        // SC :O(Target/min_nums) 
 void rec(int target,int ind,vector<int>&nums,vector<vector<int>>&res,vector<int>&vec){
                if(target==0){res.push_back(vec);return;}
               
                for(int i=ind;i<nums.size();i++){
                        if(nums[i]>target)break;
                        vec.push_back(nums[i]); 
                        rec(target-nums[i],i,nums,res,vec);
                        vec.pop_back();               
                }
                
        }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
            vector<int>vec;
            sort(nums.begin(),nums.end());
         rec(target,0,nums,res,vec);
             return res;
    }
       
        
};