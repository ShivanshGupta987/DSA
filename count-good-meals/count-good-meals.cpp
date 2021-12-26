class Solution {
public:

    int countPairs(vector<int>& nums) {
            // TC:O(N)
            //SC: O(N)
          long long int mod= 1e9+7;
          long long int ans=0;
            
            unordered_map<int,int>mp;
            for(auto n: nums){
                    for(int i=1;i<=(1<<22);i*=2){
                            if(mp.count(i-n)){ans+=mp[i-n];ans%=mod;}
                    }
                    mp[n]++;
            }
            
            return ans;
    }
};