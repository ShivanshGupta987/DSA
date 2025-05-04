class Solution {
    // TC : O(100)
    // SC : O(100)
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int>mp(100);
        int ans = 0;
        for(auto & domino : dominoes){
            int a = domino[0], b = domino[1];
            if(b<a) swap(a,b);
            ans += mp[a*10 + b];
            mp[a*10 + b]++;
        }
        return ans;
        
    }
};