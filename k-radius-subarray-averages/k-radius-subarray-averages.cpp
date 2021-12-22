class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
            // TC:O(N)
            //SC :O(N)
        
         int n=nums.size();  
            vector<int>avg(n);
        vector<long>pre(n);
        for(int i=0;i<n;i++){
                pre[i]= (i==0)?nums[0]: pre[i-1]+nums[i];
        }
            for(int i=0;i<n;i++){
              avg[i]=(i-k<0 || i+k>=n)?-1: (pre[i+k]-pre[i-k]+nums[i-k])/(2*k+1);
                
            }
           return avg; 
    }
};