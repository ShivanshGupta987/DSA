class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> cnts1o(26), cnts1e(26), cnts2o(26), cnts2e(26);
        int n = s1.size();
        for(int i=0;i<n;i++){
            if(i%2){
                cnts1o[s1[i]-'a']++;
                cnts2o[s2[i]-'a']++;
            }
            else{
                cnts1e[s1[i]-'a']++;
                cnts2e[s2[i]-'a']++;
            }
        }

        for(int i=0;i<26;i++){
            if(cnts1e[i]!=cnts2e[i] || cnts1o[i]!=cnts2o[i]) return false;
        }
        return true;
    }
};