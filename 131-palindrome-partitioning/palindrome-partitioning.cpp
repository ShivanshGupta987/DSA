class Solution {
    vector<vector<string>>res;
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }

    void backtrack(string &s, int ind, vector<string>& temp){
        int n = s.size();
        if(ind>=n){
            res.push_back(temp);
        }

        for(int j=ind; j<n; j++){
            if(isPalindrome(s, ind, j)){
                temp.push_back(s.substr(ind, j-ind+1));
                backtrack(s, j+1, temp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string>temp;
        backtrack(s, 0, temp);
        return res;
    }
};