class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>res;
        for(int k=0;k<words.size();k++){
            bool found = false;
            for(int i=0;words[k][i];i++){
                if(words[k][i]==x)found = true;
            }
            if(found)res.push_back(k);
        }
        return res;
    }
};