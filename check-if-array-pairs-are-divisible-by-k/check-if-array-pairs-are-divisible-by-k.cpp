class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
            if(arr.size()&1)return false;
            unordered_map<int,int>mp;
            for(auto x:arr){
                    int rem=(x%k + k)% k;
                    mp[rem]++;
            }
            
            for(auto &[key,value]:mp){
                 if(key==0 && value&1)return false;
                 if(key!=0 && value!=mp[k-key])return false;
                 if(key==k-key && value&1 )return false;
            }
            return true;
    }
};