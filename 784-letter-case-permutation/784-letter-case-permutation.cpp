class Solution {
        // TC:O(2^N)
        // SC:O(N)
        
        vector<string>res;
        bool isNumeric(char c){
                if(c>='0' && c<='9')return true;
                else return false;
        }
        void helper(string &s,int ind){
                
                while(ind<s.size() && isNumeric(s[ind]))ind++;
                if(ind==s.size()){res.push_back(s);return;}
                
                        helper(s,ind+1);
                        s[ind]^=(1<<5);
                        helper(s,ind+1);
                        s[ind]^=(1<<5);
              
        }
public:
    vector<string> letterCasePermutation(string s) {
            helper(s,0);
        return res;
    }
};