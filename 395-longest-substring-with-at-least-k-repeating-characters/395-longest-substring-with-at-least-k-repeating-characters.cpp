class Solution {
        // TC: O(n*k)  // n-> size of the string s
        // SC:O(1)
private:
         int getMaxUniqueLetters(string s) {
        bool map[26] = {0};
        int maxUnique = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!map[s[i] - 'a']) {
                maxUnique++;
                map[s[i] - 'a'] = true;
            }
        }
        return maxUnique;
         }
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
            int res=0;
            int mp[26];
            
           
            int mu=getMaxUniqueLetters(s);  // max unique char in string
           
            // cu -> considering only cu unique characters
            for(int cu=1;cu<=mu;cu++){
                    memset(mp,0,sizeof(mp));
                    
                   int u=0, // current unique elements 
                    l=0, r=0, ind=0, countAtLeastk=0;
                    while(r<n){
                    if(u<=cu){
                            ind= s[r]-'a';
                            if(mp[ind]==0)u++;
                            mp[ind]++;
                            if(mp[ind]==k)countAtLeastk++;
                            r++;       
                    }
                    else {
                            ind = s[l]-'a';
                            if(mp[ind]==k)countAtLeastk--;
                            mp[ind]--;
                            if(mp[ind]==0)u--;
                            
                            l++;
                    }
                    if(u==cu && u==countAtLeastk)res=max(res,r-l);
            }
            }
            return res;
    }
};

// class Solution {
//         // TC: O(n^2)
//         // SC: O(n)
//         private: 
//         // dac stands for divide and conquer
//         int dac(string s,int l, int r, int k){
                
//                 if(r<k)return 0;
                
//                 unordered_map<char,int>mp;
                
//                 for(int i=l;i<r;i++)mp[s[i]]++;
                
//                 for(int mid=l;mid<r;mid++){
//                         if(mp[s[mid]]>=k)continue;// finding invalid index having count<k
                        
//                         int mid_next=mid+1;
                        
//                         while(mid_next<r && mp[s[mid_next]]<k)mid_next++;
                  
//                         return max(dac(s,l,mid,k),dac(s,mid+1,r,k));
//                 }
//                 mp.clear();
//            return (r-l);     
//         }
// public:
//     int longestSubstring(string s, int k) {
//             int n=s.size();
//             return dac(s,0,n,k);
//     }
// };