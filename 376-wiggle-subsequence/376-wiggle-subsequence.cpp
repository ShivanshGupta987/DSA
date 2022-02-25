class Solution {
        // TC : O(N)
        // SC : O(1)
        
        // Space optimized linear dp
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
            if(n<2)return n;
            
            int up=1, down =1;
            
            for(int i=1; i<n; i++){
                    if(nums[i]<nums[i-1]) down=up+1;
                    else if(nums[i]>nums[i-1]) up = down +1;
            }
            return max(up,down);
    }
};




// class Solution {
// public:
//         // TC: O(N^2)
//         // SC: O(N)
//         // Bottom - up DP
//     int wiggleMaxLength(vector<int>& nums) {
        
//             int n=nums.size();
//             if(n<2) return n;
             
//             vector<int>up(n) , down(n);
            
//             up[0]=down[0]=1;
            
//             for(int i=1;i<n;i++){
//                     for(int j=0; j<i; j++){
//                   if(nums[j]<nums[i]) up[i] = max(up[i] , down[j]+1);
//                   else if (nums[j]>nums[i]) down[i]= max(down[i],up[j]+1);
                           
//                     }
//             }
//             return max(up[n-1],down[n-1]); 
//     }
// };