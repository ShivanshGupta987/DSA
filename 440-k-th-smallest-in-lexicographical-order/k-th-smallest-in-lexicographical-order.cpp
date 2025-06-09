class Solution {
    // TC : O((log n)^2)
    // SC : O(1)
    int countSteps(long long prefix1, long long prefix2, int n){
        int steps = 0;
        while(prefix1<=n){
            steps += min((long long)n+1,prefix2) - prefix1;
            prefix1*=10;
            prefix2*=10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        
        int cur = 1;
        k--;
        while(k>0){
            int steps = countSteps(cur, cur+1, n);

            // if steps is less than or equal to k then kth node lies in sibling subtree
            if(steps<=k){
                k-=steps;
                cur++;
            }
            // o.w. Kth node is within than subtree(go into depth)
            else{
                k--;
                cur*=10;
            }   
        }
        return cur;
    }
};