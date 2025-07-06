class FindSumPairs {
    unordered_map<int,int>mp;
    vector<int>nums1;
    vector<int>nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        int n1 = nums1.size(), n2 = nums2.size();
        for(int i=0;i<n2;i++){
            mp[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        int old_val = nums2[index];
        this->nums2[index] += val;
        mp[old_val]--;
        mp[this->nums2[index]]++;
    }
    
    int count(int tot) {
        int n1 = this->nums1.size();
        int cnt = 0;
        for(int i=0;i<n1;i++){
            if(mp.find(tot-nums1[i])!=mp.end()){
                cnt += mp[tot-nums1[i]];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */