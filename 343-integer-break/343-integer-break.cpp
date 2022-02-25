class Solution {
        // TC : O(1)
public:
    int integerBreak(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        if(n==4)return 4;
        if(n%3==1)return 4*pow(3,(n-4)/3);  
   
        if(n%3==2) return 2*pow(3,(n-2)/3);
        return pow(3,n/3);
    }
};