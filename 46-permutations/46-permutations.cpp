#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
        vvi res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        bt(0,nums);
            return res;
            
    }
        private:
        void bt(int ind, vector<int>& nums){
                if(ind==nums.size())res.push_back(nums);
           for(int i=ind;i<nums.size();i++ ){
                  swap(nums[i],nums[ind]);
                   bt(ind+1,nums);
                   swap(nums[i],nums[ind]);
           }  
        }
        
};