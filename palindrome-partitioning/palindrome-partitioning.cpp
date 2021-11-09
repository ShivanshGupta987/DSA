class Solution {
public:
    bool isPalindrome(string &s,int i,int j){            
            for(;i<j;(i++,j--)){
                    if(s[i]!=s[j])return false;
            }
            return true;
    }

  void backtrack(int ind1,string &s,vector<string>&vec,vector<vector<string>>&ans){
          
      if(ind1==s.size()){
              ans.push_back(vec);return;
      }
          
    for(int i=ind1;i<s.size();i++){
            if(isPalindrome(s,ind1,i)){vec.push_back(s.substr(ind1,i-ind1+1));
            backtrack(i+1,s,vec,ans);
             vec.pop_back();
                       }
    }  
          
  }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
            vector<string>vec;
     backtrack(0,s,vec,ans);
    
            return  ans;
    }
};