class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int>idx(n+2);
        vector<char>symbols(n+2);
        int len = 1;
        idx[0] = -1;
        symbols[0] = 'L';
        
        for(int i=0;i<n;i++){
            if(dominoes[i]!='.'){
                idx[len] = i;
                symbols[len++] = dominoes[i];
            }
        }
        idx[len] = n;
        symbols[len++] = 'R';
        string ans = dominoes;

        for(int k=0;k<len-1;k++){
            int i = idx[k], j = idx[k+1];
            char x = symbols[k], y = symbols[k+1];

            if(x==y){
                for(int p=i+1;p<j;p++){
                    ans[p] = x;
                }
            }
            else if(x>y){ // R...L case
                for(int p=i+1; p<j; p++){
                    ans[p] = p-i == j-p ? '.' : p-i < j-p ? 'R' : 'L'; 
                }
            }
        }
        return ans;
        
    }
};