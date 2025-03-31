class Solution {
    // TC : O(N)
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long res = 0;
        int n = weights.size();
        vector<int>adjps;
        for(int i=0;i<n-1;i++){
            adjps.push_back(weights[i]+weights[i+1]);
        }
        sort(adjps.begin(), adjps.end());
        int m = adjps.size();
        for(int i=0;i<k-1;i++){
            res += adjps[m-i-1] - adjps[i];
        }
        return res;
    }
};