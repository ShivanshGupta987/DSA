class Solution {
        // TC : O(N)
        // SC : O(1)
        // N -> preorder.size()
public:
    bool isValidSerialization(string preorder) {
        
          int capacity = 1;
          if(preorder.empty()) return false;
           preorder += ',';
            
            for(int i=1;preorder[i];i++){
                    
                 if(preorder[i]!=',') continue;
                 capacity--;
                 if(capacity<0) return false;
                 if(preorder[i-1]!='#') capacity+=2;
                  
            }
           return capacity == 0;
    }

};