class Solution {
    // TC : O(min(n, limit))
public:
    long long distributeCandies(int n, int limit) {
        
        long long cnt = 0;
        for(int i=0;i<=min(limit,n);i++){
            cnt += max(0, min(limit, n-i) - max(0, n-i-limit)+1);
        }
        return cnt;
    }
};