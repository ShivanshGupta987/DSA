class Solution {
  vector<vector<int>>res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
            for(int k=0;k<=nums.size();k++){
                    rec(0,k,nums,temp);
            }
            return res;
    }
        private:
        void rec(int ind,int k,vector<int>& nums,vector<int>&temp ){
                if(k==0){res.push_back(temp);return;}
                for(int i=ind;i<nums.size();i++){
                        temp.push_back(nums[i]);
                        rec(i+1,k-1,nums,temp);
                        temp.pop_back();
                }
        }
};