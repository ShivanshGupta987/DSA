class Solution {
        // TC : O(log N)
        // N -> label
public:
    vector<int> pathInZigZagTree(int label) {
        
            int level = floor(log2(label))+1;
            
            vector<int>res(level);
            
            for(;level>=1;--level,label/=2){
                    res[level-1] = label;
                    label = (1<<level) - label + (1<<(level-1)) - 1;
            }
            return res;
    }
};