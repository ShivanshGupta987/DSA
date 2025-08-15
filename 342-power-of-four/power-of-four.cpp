class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int mask = 0x55555555;
        if((mask&n) && ((n&(n-1))==0)) return true;
        else return false;
    }
};