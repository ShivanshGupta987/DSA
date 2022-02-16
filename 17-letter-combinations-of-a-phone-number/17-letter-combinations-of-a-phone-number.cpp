class Solution {
        // TC: (3^N)  // N-> digits.size()
        // SC: O(N)
        vector<string>res;
        void helper(string &digits,vector<string>&tel,string &comb,int i ){
                if(i==digits.size()){
                        res.push_back(comb);return;
                }
                int k=digits[i]-'0';
                for(int j=0;j<tel[k].size();j++){
                        comb.push_back(tel[k][j]);
                        helper(digits,tel,comb,i+1);
                        comb.pop_back();
                }
        }
public:
    vector<string> letterCombinations(string digits) {
       vector<string>tel{"","","abc","def","ghi","jkl","mno","pqrs","tuv",
                      "wxyz"};
       string comb;
       if(digits.size()==0)return {};
       helper(digits,tel,comb,0);  
       return res;
    }
};