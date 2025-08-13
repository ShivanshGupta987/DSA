class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int x = 1;
        while(x*3ll<=(long long)n){
            x*=3;
        }
        return x==n;
    }
};