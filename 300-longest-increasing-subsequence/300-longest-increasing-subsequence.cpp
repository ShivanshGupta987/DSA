class Solution {
public:
        // TC: O(N log N)
        // SC: O(N)
    int lengthOfLIS(vector<int>& nums) {
            int n=nums.size();
            
        vector<int>a{nums[0]};
            
            for(int k=1;k<n;k++){
                  if(nums[k]>a.back())a.push_back(nums[k]); 
                    else {
//                             int ans=0;
//                             int i=0,j=a.size()-1;
//                             while(i<=j){
//                                     int mid= i+(j-i)/2;
                                    
//                                     if(a[mid]>=nums[k]){
//                                             ans=mid;
//                                             j=mid-1;
//                                     }
//                                     else {
//                                             i=mid+1;
//                                     }
//                             }
                            
               int ans = lower_bound(a.begin(),a.end(), nums[k]) - a.begin();
               a[ans]=nums[k];
                            
                            
                    }
            }
            return a.size();
    }
};