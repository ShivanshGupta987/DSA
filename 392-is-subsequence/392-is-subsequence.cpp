


class Solution {
        // TC : O(N)
        // SC : O(1)
        // N -> t.size()
public:
    bool isSubsequence(string s, string t) {
            if(s.size()==0) return true;
                 
            for(int i=0, j=0 ;i<t.size();i++){
                  if(s[j]==t[i])j++;
                  if(j==s.size())return true;  
                  
            }
            return false;
    }
};