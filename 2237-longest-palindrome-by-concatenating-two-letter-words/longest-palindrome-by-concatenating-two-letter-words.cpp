class Solution {
    // TC : O(N)
    // SC : O(N)
    // N : WORDS.SIZE
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        for(auto & word : words){
            mp[word]++;
        }
        int ans = 0;
        bool extra_pair = false; // check existance of standalone symmetric pair

        for(auto word : mp){
            string temp(word.first.rbegin(), word.first.rend());
            // cout<<temp<<" ";
            if(temp[0]==temp[1]){
                if(mp[temp]%2==1) extra_pair = true;
                ans += 2*(mp[temp] - mp[temp]%2);
            }
            else ans += 2*min(mp[word.first], mp[temp]);
            // cout<<ans<<" ";
        }
        return ans + (extra_pair?2:0);
    }
};