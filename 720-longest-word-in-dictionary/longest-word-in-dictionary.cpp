class Solution {
    // TC : O(30*N*logN)
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        int n = words.size();
        string ans = "";
        unordered_set<string>st;
        st.insert("");
        for(auto & word : words){
            int sz = word.size();
            if(st.count(word.substr(0, sz-1))){
                st.insert(word);
                if((ans.size() < sz) || (ans.size() == sz && word < ans)){
                    ans = word;
                }
            }
        }
        return ans;
    }
};