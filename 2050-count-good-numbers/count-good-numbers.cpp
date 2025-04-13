class Solution {
    // TC : O(log n)
    // SC : O(1)
    
    const long long mod = 1e9 + 7;
    long long fast_expo(int base, long long pow){
        if(pow==0) return 1;
        long long x = fast_expo(base, pow/2ll);
        x = (x*x)%mod;
        if(pow%2==1) return ((long long)base*x)%mod;
        else return x;
    }
public:
    int countGoodNumbers(long long n) {
        long long ans = (fast_expo(5, (n+1)/2ll)*fast_expo(4, n/2ll))%mod;
        return ans;
    }
};