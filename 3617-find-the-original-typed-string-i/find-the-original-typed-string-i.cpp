class Solution {
    // TC : O(N)
    // SC : O(1)
public:
    int possibleStringCount(string word) {
        int ans = 1;
    
        for(int i=1;word[i];i++){
            if(word[i]==word[i-1])ans++;
        }
    
        return ans;
    }
};