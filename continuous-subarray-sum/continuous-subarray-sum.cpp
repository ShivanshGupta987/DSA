class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
            // TC: O(N)
            // SC: O(N)
        map<int,int>mp={{0,-1}};
           int mod_prefix_sum=0;
            for(int i=0;i<nums.size();i++){
                    mod_prefix_sum= (mod_prefix_sum + nums[i])%k;  
                    if(mp.count(mod_prefix_sum) ){
                            if(i-mp[mod_prefix_sum]>1)return true;  // since size of subarray must be atleast two
                    }
                    else mp[mod_prefix_sum]=i;
            }
            return false;
    }
};

//    Logic behind the probem
  
//    find i , j such that sum(arr[i:j)) is multiple of k
//    accum[i]= sum(arr[0:i))
//    accum[j]= sum(arr[0:j))

//    sum(arr[i:j)) = accum[j]-accum[i]
//    let us assume 
//    accum[i]= a*k + b
//    accum[j]= c*k + d
   
//    where 0 <= b,d < k
//    case 1 : b==0 
//           accum[i] = sum(arr[0:i))  is itself multiple of k
          
//    case 2 : b,d have value other than zero
//    sum(arr[i:j))= (a-c)*k + (b-d)
           
//     as we know sum(arr[i:j)) is multiple of k
//     hence b must be equal to d
    
//     -----------------------------------------
     
    
   