class Solution {
        // DYNAMIC TABULATION APPROACH
        // TC: O(N^2)
        // SC: O(N)
public:
    int numTrees(int n) {
        vector<int>mem(n+1);
            mem[0]=mem[1]=1;
            
            
            for(int i=2;i<=n;i++){
                    for(int j=1;j<=i;j++){
                            mem[i]+=mem[j-1]*mem[i-j];
                    }
                    
            }
            return mem[n];
            
    }
};