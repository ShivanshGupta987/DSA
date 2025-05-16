class Solution {
    // TC : O(N*N)
    // SC : O(N)
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        
        int n = groups.size();
        vector<int>prev(n, -1), dp(n, 1);
        int ind = 0; // ending index of largest subsequence
        int max_sz = 1;
        for(int i=0;i<n;i++){
            for(int j=0; j<i; j++){
                if(groups[j]==groups[i] || words[j].size() != words[i].size())continue;
                int hd = 0;
                for(int k=0;k<words[j].size();k++){
                    if(words[j][k]!=words[i][k]) hd++;
                }
                if(hd!=1) continue;
                if(dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    prev[i] = j;
                }
            }
            if(dp[i] > max_sz){
                max_sz = dp[i];
                ind = i;
            }
            // cout<<dp[i]<<" ";
        }
        vector<string>res;
        while(ind!=-1){
            res.push_back(words[ind]);
            ind = prev[ind];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};