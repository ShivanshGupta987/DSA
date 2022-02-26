class Solution {
   // TC : O(N*(2^N))
   // SC : O(N + 2^N) // space for stack -> N || space for memo -> 2^N 
        
  int possible_square_side;
  map<pair<int,int>,bool>memo;
  vector<int> nums;
        
private: 
    bool recurse(int mask, int sideFormed){
        
         pair<int,int>key = {mask,sideFormed};
         
         if(memo.find(key)!=memo.end())return memo[key];
            
            
        int total_sum=0;   // sum of all the used elements till now
        for(int i=0;i<nums.size();i++){
             if((mask & (1<<i))==0 )  total_sum += nums[i]; 
        }   
         
        if(total_sum >0 && total_sum % possible_square_side==0 )sideFormed++;
            
         if(sideFormed==3)return true;
            
         bool ans = false;
            
         int c= total_sum/ possible_square_side;
            
         int rem = possible_square_side*(c+1) - total_sum;
            
         for(int i=0;i<nums.size();i++){
                 if(nums[i]<=rem && (mask & (1<<i))){
                         if(recurse(mask^(1<<i),sideFormed))
                         { ans=true;break;}
                 }
         }
            return memo[key]=ans;
            
        
    }
public:
    bool makesquare(vector<int>& arr) {
            
        int sum = accumulate(arr.begin(),arr.end(),0);
        
        if(sum%4 || arr.size()<4)return false;
            
        possible_square_side = sum/4;
        
        int L = arr.size();
        nums = arr;
        return recurse((1<<L)-1,0);
            
    }
};




















// // TC: O(4^N)
// // SC: O(N)
// class Solution {
        
//         int lar=0; // length of the largest possible matchstick
//         vector<int>sums; // to store current length of sides 
       
//         bool dfs(vector<int>& ms,int ind ){
//                 if(ind==ms.size())
//                 return sums[0]==sums[1]&& sums[1]==sums[2] && sums[2]==sums[3];
                
//                 int element=ms[ind];
                
//                 for(int i=0;i<4;i++){
//                         if(sums[i]+element<=lar)
//                         {
//                            sums[i]+=element;
//                            if(dfs(ms,ind+1))return true;
//                            sums[i]-=element;
//                         }
//                 }
//                 return false;
                
//         }   
// public:
//     bool makesquare(vector<int>& ms) {
            
//             int sum = accumulate(ms.begin(),ms.end(),0); 
//             if(sum %4!=0)return false;
//             sort(ms.begin(),ms.end(),greater<int>()); 
//             sums.resize(4);
//             lar=sum/4;
//             return dfs(ms,0);
           
//     }
// };