class Solution {
    // TC : O(N*100*log(100))
    // SC : O(N*100)
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<int>>mp;
        for(int i=0;i<n;i++){
            string str = strs[i];
            sort(str.begin(), str.end());
            mp[str].push_back(i);
        }   

        vector<vector<string>>res;
        for(auto &[key, value]: mp){
            res.push_back({});
            for(int idx : value){
                res.back().push_back(strs[idx]);
            }
        }
        return res;
    }
};