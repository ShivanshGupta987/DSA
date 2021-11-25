class FindSumPairs {
private:
       unordered_map<int,int>mp;
        map<int,int>first; 
        vector<int>nums2;
public:
    
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
            nums2=n2;
          
        for(int x:n1)first[x]++;
        for(int x:n2)mp[x]++;
    }
    
    void add(int index, int val) {
            mp[nums2[index]]--;
            nums2[index]+=val;
            mp[nums2[index]]++;
    }
    
    int count(int tot) {
            int ans=0;
        for(auto itr=first.begin(); itr!=first.end() && itr->first<tot;itr++){
                if(mp.count(tot-itr->first))ans+=mp[tot-itr->first]*(itr->second);
        }
            return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */