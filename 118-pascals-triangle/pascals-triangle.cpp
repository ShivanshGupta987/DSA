class Solution {
    // TC : O(N*N)
    // SC : O(N*N)
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>res;
        res.push_back({1});
        for(int sz=2; sz<=n; sz++){
            vector<int>temp(sz,1);
            for(int i=1;i<sz-1;i++){
                temp[i] = res.back()[i] + res.back()[i-1];
            }
            res.push_back(temp);
        }
        return res;
    }
};