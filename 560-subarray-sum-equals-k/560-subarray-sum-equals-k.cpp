class Solution{ 
        // TC: O(N)
        // SC: O(N)
public:
    int subarraySum(vector<int>& a, int k) {
        unordered_map<int,int>mp;
            int n=a.size();
            mp.insert({0,1});
            int sum=0;
            int count =0;
           for(int i=0;i<n;i++){
                   sum+=a[i];
                if(mp.find(sum-k)!=mp.end()) count+=mp[sum-k];  
                mp[sum]++;
           }
         return count;  
    }
};