class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.size() < k){
            int sz = word.size();
            for(int i=0;i<sz;i++){
                word += 'a' + (word[i]-'a' + 1)%26; 
            } 
            // cout<<word<<" ";
        }
        return word[k-1];
    }
};