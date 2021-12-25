class Solution {
public:
    string minWindow(string s, string t) {
//            int len=INT_MAX; int ind=-1;
//            unordered_map<char,int>dict_t;
//            unordered_map<char,int>window_count;
            
//             for(auto c:t)dict_t[c]++;
//             int required=dict_t.size();// No. of unique characters in string t
//             int formed =0 ; // Counter for current window
//             int r=0,l=0;
//             while(r < s.size())
//             {
            
//                     window_count[s[r]]++;
                    
//                     if(dict_t.find(s[r])!=dict_t.end() && window_count[s[r]]==dict_t[s[r]])formed++;
                    
//                     while(l<=r && formed== required)
//                     {
//                             if(len>r-l+1){len=r-l+1; ind =l;}
//                             window_count[s[l]]--;
//                             if(dict_t.find(s[l])!=dict_t.end() && window_count[s[l]]<dict_t[s[l]])formed--;
//                             l++;
//                     }
//                     r++;
//             }
//            if(len==INT_MAX)return "";
//             return s.substr(ind,len);
            
            vector<int>map ( 128 , 0);
            int length=INT_MAX;
            int ind=0, end=0, begin=0;
            int counter=t.size();
            for(auto c: t) map[c]++;
            
            while(end<s.size()){
                    if(map[s[end++]]-->0) counter--;
                    
                    while(counter==0){
                            if(end-begin<length) length=end-(ind=begin);
                            if(map[s[begin++]]++==0)counter++;
                           
                    }
            }
            return (length==INT_MAX)? "" : s.substr(ind,length);
            
        
    }
   
};