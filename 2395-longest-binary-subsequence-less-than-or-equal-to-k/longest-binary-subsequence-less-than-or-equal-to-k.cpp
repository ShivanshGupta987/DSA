class Solution {
    // TC : O(N)
    // SC : O(1)
public:
    int longestSubsequence(string s, int k) {
        int sum = 0;
        int cnt = 0;
        int bits = 32 - __builtin_clz(k);
        int n = s.size();
        for(int i=0;i<n;i++){
            char ch = s[n-i-1];
            if(ch=='1'){
                if(i<bits && (sum + (1<<i)) <=k ){
                    cnt++;
                    sum += 1<<i;
                }
            }
            else cnt++;
        }
        return cnt;
    }
};