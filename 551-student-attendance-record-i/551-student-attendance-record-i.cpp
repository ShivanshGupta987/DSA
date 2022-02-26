class Solution {
        // TC : O(N)
        // SC : O(1)
public:
    bool checkRecord(string s) {
            int absent = 0 , cons_late = 0;
        for(int i=0;s[i];i++){
             if(s[i]=='A')absent++;
             if(s[i]=='L')cons_late++;
             else cons_late = 0;
             if(absent>1 || cons_late>=3)return false;
        }
            return true;
    }
};