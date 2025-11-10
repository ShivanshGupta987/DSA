class Solution {
    // TC : O(N*(100 + log(100)))
    // SC : O(N*100)
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,int>mp;
        vector<vector<string>>res;
        for(int i=0;i<n;i++){
            string str = strs[i];
            sort(str.begin(), str.end());

            if(!mp.contains(str)){
                mp[str] = res.size();
                res.push_back({});
            }
            res[mp[str]].push_back(strs[i]);
        }   

        return res;
    }
};