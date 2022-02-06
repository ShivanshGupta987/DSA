class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
            int n=nums.size();
        vector<vector<int>>res(pow(2,n),vector<int>());
            for(int i=0;i<(1<<n);i++){
                    for(int j=0;j<n;j++){
                            if(i&(1<<j))res[i].push_back(nums[j]);
                    }
          
            }
            return res;
    }
};