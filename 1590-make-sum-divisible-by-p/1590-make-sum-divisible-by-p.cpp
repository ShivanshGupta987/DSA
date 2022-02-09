class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
            //TC:O(N)
            // SC: O(p)
        
          int need=0;
          
          for(auto n:nums)need=(need+n)%p;
          if(need==0)return 0; 

          unordered_map<int,int>mp{{0,-1}};
            int cur=0,len=INT_MAX;
            for(int i=0;i<nums.size();i++){
                   cur=(cur+nums[i])%p;
                    mp[cur]=i;  
                   int req=(cur-need+p)%p;
                   if(mp.count(req)){
                           len=min(len,i-mp[req]);
                   } 
                   
                   
            }
            
            return (len==nums.size())?-1:len;
   
            
            
            
    }
};