class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           int len=0;
           int i=0;
            int n=s.size();
           unordered_map<char,int>mp;
            for(int j=0;j<n;j++){
                if(mp.find(s[j])!=mp.end())i=max(mp[s[j]],i);
                
                 len=max(len,j-i+1);
                    mp[s[j]]=j+1;
            }
            
     return len;       
    }
};
