class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        long long ans=0;
            int n=nums.size();
            vector<long long>pref(n),suff(n);
            pref[0]=nums[0]; suff[n-1]=nums[n-1];
            for(int i=1;i<n;i++){
                    pref[i]=pref[i-1]+nums[i];
                    suff[n-i-1]=suff[n-i]+nums[n-i-1];
            }
            
            unordered_map<long long ,long long>left,right;
            for(int i=0;i<n-1;i++)right[pref[i]-suff[i+1]]++;
            if(right.count(0))ans=right[0];
            
            for(int i=0;i<n;i++){
                    long long  diff=k-nums[i];
                    long long cur=0;
                    if(right.count(-diff))cur+=right[-diff];
                    if(left.count(diff))cur+=left[diff];
                    
                    ans=max(ans,cur);
                    if(i<n-1){
                            long long int d=pref[i]-suff[i+1];
                            left[d]++;
                            right[d]--;
                            if(right[d]==0)right.erase(d);
                    }
                    
            }
            return ans;
    }
        
};