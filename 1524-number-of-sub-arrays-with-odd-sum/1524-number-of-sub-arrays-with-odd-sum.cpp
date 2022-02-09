class Solution {
 #define mod 1000000007
        // TC: O(N)
        // SC: O(1)
public:
    int numOfSubarrays(vector<int>& arr) {
        int count =0;
         int mp[2]={1,0};
            int sum=0;
            for(auto x :arr){
                    sum=(sum+x)%2;
                   if(sum%2){
                           mp[1]++;
                           count =(count + mp[0])%mod;
                   }
                    else {
                            mp[0]++;
                            count=(count + mp[1])%mod;
                    }
            }
            return count;
    }
};