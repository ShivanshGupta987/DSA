class Solution {
    // TC :O(N)
    // SC : O(1)
public:
    int maxDifference(string s) {
        vector<int>cnt(26);
        int max_odd = 0, min_even = s.size();
        for(int i=0;s[i];i++){
            cnt[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]==0) continue;
            if(cnt[i]%2) max_odd = max(max_odd, cnt[i]);
            else min_even = min(min_even, cnt[i]);
        }
        return max_odd-min_even;
    }
};