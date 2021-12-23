class Solution {
public:
        
        // TC: O(s.size())
    int lengthOfLongestSubstring(string s) {
          int len=0;
            unordered_map<char,int>mp;
             int i=0;
            for(int j=0;s[j];j++){
                    if(mp.find(s[j])!=mp.end())i=max(mp[s[j]]+1,i);
                    len=max(len,j-i+1);
                    mp[s[j]]=j;
                    
            }
            
     return len;       
    }
};
