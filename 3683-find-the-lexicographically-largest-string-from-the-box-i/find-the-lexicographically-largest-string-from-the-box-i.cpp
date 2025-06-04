class Solution {
    // TC : O(N)
    string get_lastSubstring(string word){
        int n = word.size();
        int s1_left = 0, s2_left = 1;
        while(s2_left < n){
            int k = 0;
            while(s2_left+k<n && word[s1_left+k] == word[s2_left+k]){
                k++;
            }
            if(s2_left+k<n && word[s1_left+k] < word[s2_left+k]){
                int t = s1_left;
                s1_left = s2_left;
                s2_left = max(s2_left+1, t+k+1);
            }
            else s2_left = s2_left+k+1;
        }
        return word.substr(s1_left,n-s1_left);
    }
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        string last = get_lastSubstring(word);
        int n = word.size(), m = last.size();
        return last.substr(0, min(m, n-numFriends+1));
    }
};