class Solution {
        // TC: O(N)
        // SC:O(N)
        private:
        int dp(vector<int>&a){
                int n=a.size();
                vector<int>mem(a);
                mem[1]=max(a[0],a[1]);
                for(int i=2;i<n;i++){
                        mem[i]=max(mem[i-1],a[i]+mem[i-2]);
                }
                return mem.back();
        }
public:
    int rob(vector<int>& nums) {
            int n=nums.size();
        if(n==1)return nums[0];
            if(n==2)return max(nums[0],nums[1]);
            vector<int>x(nums.begin()+1,nums.end());
            vector<int>y(nums.begin(),nums.end()-1);
        
            return max(dp(x),dp(y));
    }
};