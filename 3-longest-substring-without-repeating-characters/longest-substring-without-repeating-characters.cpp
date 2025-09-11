class Solution {
    // TC : O(N)
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>last_idx;

        int n = s.size();
        int left = 0;
        int ans = 0;
        for(int right=0;right<n;right++){
            int ch = s[right]-'a';
            if(last_idx.find(ch)!= last_idx.end() && last_idx[ch] >= left){
                left = last_idx[ch]+1;
            }
            last_idx[ch] = right;
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};