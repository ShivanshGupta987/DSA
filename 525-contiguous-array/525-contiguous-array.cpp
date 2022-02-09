class Solution {
 
public:
    int findMaxLength(vector<int>& nums) {
        
            
            int n=nums.size();
            int base =0; // counter 
            unordered_map<int,int>mp{{0,-1}};
            int maxlen=0;
            for(int i=0;i<n;i++){
                  // if current element is 0 then increase it by 1 else decrease it by 1
                  base = (nums[i]==1)?base+1:base-1;
                       
                  if(mp.find(base)==mp.end())mp[base]=i;
                    
                  else  maxlen=max(maxlen,i-mp[base]);
                 
            }
            return maxlen;
            
            
    }
};

//  Brute Force
//  TC:O(N^2)
//  SC:O(N)

// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//        int n=nums.size();
//            int len =0;
//            int pre[n];
//             memset(pre,0,sizeof(pre));
//             pre[0]=nums[0];
//             for(int i=1;i<n;i++)pre[i]+=pre[i-1]+nums[i];
//             for(int j=n-1;j>=1;j--){
//                     for(int i=(j+1)&1; i<j;i+=2){
//           if(pre[j]-pre[i]+nums[i]==(j-i+1)/2)len=max(len,j-i+1);
//                     }
//             }
//             return len;
//     }
// };