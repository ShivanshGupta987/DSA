class Solution {
public:
    long long minimumPerimeter(long long apples) {
            // TC: O(log(1e5))
            long long  r= 1e5;
            
            long long l=1;
            while(l<=r){
                    long long mid= l+(r-l)/2;
                    long long x=2*mid*(mid+1)*(2*mid+1);
                    if(x>apples)r=mid-1;
                    else if(x==apples)return 8*mid;
                    else l=mid+1;
            }
            return 8*l;
    }
};