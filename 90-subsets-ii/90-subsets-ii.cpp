class Solution {
       vector<vector<int>>res;
        void helper(vector<int>& nums,vector<int>&comb, int ind, int len){
                if(len==0){res.push_back(comb); return;}
                
                for(int i=ind;i<nums.size();i++){
                        if(i-ind>0 && nums[i]==nums[i-1])continue;
                        comb.push_back(nums[i]);
                        helper(nums,comb,i+1,len-1);
                        comb.pop_back();
                }
                
        }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
            vector<int>comb;
            for(int i=0;i<=nums.size();i++){
                    helper(nums,comb,0,i);
            }
            return res;
    }
};