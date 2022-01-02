class Solution {
public:
    bool isAnagram(string s, string t) {
            unordered_map<char,int>mp;
            
            for(auto c:s){
                    mp[c]++;
            }
            for(auto c:t){
                    mp[c]--;
                    if(mp[c]==0)mp.erase(c);
            }
            return mp.size()==0;
        
    }
};