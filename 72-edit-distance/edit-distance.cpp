class Solution {
    // TC : O(N*M)
    // WHERE N = WORD1.SIZE(), M = WORD2.SIZE()
    int INF = 1000;
    int dp[501][501];
    int rec(int i, int j, string & word1, string & word2){
        int n = word1.size(), m = word2.size();
        if(i==n || j==m) return max(n-i, m-j);
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INF;
        // case 1 : same char
        if(word1[i]==word2[j]){
            ans = rec(i+1, j+1, word1, word2);
        }
        // case 2 : replace word1[i]
        ans = min(ans, 1 + rec(i+1, j+1, word1, word2));

        // case 3 : insert at ith pos in word1
        ans = min(ans, 1 + rec(i, j+1, word1, word2));

        // case 4 : delete at ith pos in word1
        ans = min(ans, 1 + rec(i+1, j, word1, word2));

        // case 5 (same as case 2) : replace word2[j]

        // case 6 (same as case 4): insert at jth pos in word2
        // ans = min(ans, 1 + rec(i+1, j, word1, word2));

        // case 7 (same as case 3): delete at jth pos in word2
        ans = min(ans, 1 + rec(i, j+1, word1, word2));

        return dp[i][j] = ans;
    }
public:
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, word1, word2);
    }
};